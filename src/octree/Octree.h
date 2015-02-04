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

class Node;
class OctreeEntry;

class Octree : public Node
{
    protected:
        int depth;
    
    public:
    static int size;
    static float subSize;
    float p;
    float q;
    float r;
    
        static void bufferizeEntry(GlobalBuffer* buffer, unsigned char, float p, float q, float r, float* ao, float width);
        Octree() : Node()
        {
            depth = 5;
        }

        ~Octree()
        {
            //OctreeEntry<T>::~OctreeEntry();
        }
    
        void bufferize(GlobalBuffer* buffer, float x, float y, float z);
        void bufferize(VBOScene* scene, OctreeEntry* OctreeEntry, float p, float q, float r, int size);
        void setSize(int size){this->size=size;};
        void setSubSize(int subSize){this->subSize=subSize;};
        bool isCubeVisible(int x, int y, int z, int size);
};

#endif /* defined(__Voxelengine__Octree__) */
