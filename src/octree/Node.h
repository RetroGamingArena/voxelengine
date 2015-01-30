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

#include "OctreeEntry.h"
#include "Leaf.h"

class Node : public OctreeEntry
{
    protected:
        OctreeEntry** entries;

    public:
        Node()
        {
            entries = 0;
        }
        ~Node()
        {
            if( this->entries != NULL )
                for(int i = 0; i < 8; i++)
                {
                    if( this->entries[i] != NULL )
                    {
                        delete this->entries[i];
                        //TemplateDebug::debug();
                        this->entries[i] = NULL;
                    }
                }
            delete[] this->entries;
        }
        OctreeEntry** getEntries(){return entries;};
    
        void split();
        OctreeEntry* get(int x, int y, int z);
        OctreeEntry* addAndGet(int x, int y, int z, bool leaf);
        Leaf* getAbs(int x, int y, int z, int size);
        void setCube(int x, int y, int z, int size, unsigned char type);
        void invalidate();
        bool isCompressible();
};

#endif /* defined(__Voxelengine__Node__) */
