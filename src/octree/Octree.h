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
    
        
        Octree() : Node()
        {
            depth = 5;
        }

        ~Octree()
        {
            //OctreeEntry<T>::~OctreeEntry();
        }
    
        void bufferize(GlobalBuffer* buffer, float x, float y, float z);
        void setSize(int size){this->size=size;};
        void setSubSize(int subSize){this->subSize=subSize;};
};

#endif /* defined(__Voxelengine__Octree__) */
