//
//  Octree.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 07/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include "Octree.h"
#include "../world/Cube.h"
#include "../world/CubeType.h"
#include "../octree/Leaf.h"

int Octree::size = 0;
float Octree::subSize = 0;

void Octree::bufferize(GlobalBuffer* buffer, float p, float q, float r) //TODO octree offset
{
    for(int i = 0; i < 8; i++)
    {
        int x = (i%4)%2;
        int y = i/4;
        int z = (i%4)/2;

            //bufferize(scene, this->entries[i], p+x*size/2.0, q+y*size/2.0, r+z*size/2.0, size/2.0);
        if(this->entries[i] != NULL)
            this->entries[i]->bufferize(buffer, this->p*size+x*size/2.0, this->q*size+y*size/2.0, this->r*size+z*size/2.0, size/2.0);
    }
}

