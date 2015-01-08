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
#include "OctreeEntry.h"
#include "OctreeEntry.cpp"

template<typename T>
class Octree : public OctreeEntry<T>
{
    int depth;
    int size;
    
    public:
    Octree() : OctreeEntry<T>()
    {
        depth = 5;
    }
    
    void bufferize(VBOScene* scene, float x, float y, float z);
    void bufferize(VBOScene* scene, OctreeEntry<T>* OctreeEntry, float p, float q, float r, int size);
    void setSize(int size){this->size=size;};
};

#endif /* defined(__Voxelengine__Octree__) */
