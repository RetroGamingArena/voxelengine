//
//  Leaf.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 25/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include "Leaf.h"
#include "../engine/engine.h"
#include "../world/CubeType.h"

void Leaf::invalidate()
{
    //this->drawn = 0;
}

void Leaf::setCube(int x, int y, int z, int size, unsigned char type)
{
    this->leaf = type;
}

void Leaf::bufferize(GlobalBuffer* buffer, float p, float q, float r, int size)
{
    {
        if(getLeaf() > 0)
        {
            if(Engine::getInstance()->getWorld()->isCubeVisible(p,q,r))
            {
                glm::vec3 color = CubeType::getColor(getLeaf(), q);
                
                int x = 0;
                int y = 0;
                int z = 0;
                
                float* ao = new float[4];
                
                ao[0] = 0.5;
                ao[1] = 0.5;
                ao[2] = 0.5;
                ao[3] = 0.5;
        
                Octree::bufferizeEntry(buffer, getLeaf(), p/Chunk::subsize, q/Chunk::subsize, r/Chunk::subsize, ao, size);
                
                ao[0] = 0;
                ao[1] = 0;
                ao[2] = 0;
                ao[3] = 0;
            }
        }
    }
}

unsigned char Leaf::getAbs(int x, int y, int z, int size)
{
    return this->getLeaf();
}