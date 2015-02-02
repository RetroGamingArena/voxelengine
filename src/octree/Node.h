//
//  Node.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 26/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#ifndef __Voxelengine__Node__
#define __Voxelengine__Node__

#include <stdio.h>
#include <vector>

#include "OctreeEntry.h"
#include "Leaf.h"

class Octree;

class Node : public OctreeEntry
{
    protected:
    std::vector<OctreeEntry*> entries;

    public:
        Node()
        {
            split();
        }
        ~Node()
        {
            /*if( this->entries != NULL )
                for(int i = 0; i < 8; i++)
                {
                    if( this->entries[i] != NULL )
                    {
                        delete this->entries[i];
                        this->entries[i] = NULL;
                    }
                }
            delete[] this->entries;*/
        }
         std::vector<OctreeEntry*> getEntries(){return entries;};
    
        void split();
        OctreeEntry* get(int x, int y, int z);
        OctreeEntry* addAndGet(int x, int y, int z, bool leaf);
        Leaf* getAbs(int x, int y, int z, int size);
        void setCube(int x, int y, int z, int size, unsigned char type);
        void invalidate();
        bool isCompressible();
        void bufferize(VBOScene* scene, float p, float q, float r, int size);
};

#endif /* defined(__Voxelengine__Node__) */
