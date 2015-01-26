//
//  Octree.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 07/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#ifndef __Voxelengine__Octree__
#define __Voxelengine__Octree__

#include <stdio.h>

#include "../scene/VBOScene.h"
#include "Node.h"

class Octree : public Node
{
    int size;
    float subSize;

    protected:
        int depth;
    
    public:
    float p;
    float q;
    float r;
    
        void bufferizeEntry(VBOScene* scene, unsigned char, float p, float q, float r, float* ao);
        Octree() : Node()
        {
            depth = 5;
        }

        ~Octree()
        {
            //OctreeEntry<T>::~OctreeEntry();
        }
    
        void bufferize(VBOScene* scene, float x, float y, float z);
        void bufferize(VBOScene* scene, OctreeEntry* OctreeEntry, float p, float q, float r, int size);
        void setSize(int size){this->size=size;};
        void setSubSize(int subSize){this->subSize=subSize;};
        bool isCubeVisible(int x, int y, int z);
};

#endif /* defined(__Voxelengine__Octree__) */
