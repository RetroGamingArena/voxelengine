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

void Leaf::bufferize(VBOScene* scene, float p, float q, float r, int size)
{
    //Leaf* leaf = dynamic_cast<Leaf*>(octreeEntry);
    //if(leaf != NULL)
    {
        if(/*leaf->*/getLeaf() > 0)
        {
            /*int abs_x = p;
            while (abs_x<0)
                abs_x += this->size; //temp
            abs_x = abs_x % this->size;
            
            int abs_y = q;
            while (abs_y<0)
                abs_y += this->size; //temp
            abs_y = abs_y % this->size;
            
            int abs_z = r;
            while (abs_z<0)
                abs_z += this->size; //temp
            abs_z = abs_z % this->size;*/
            
            if(Engine::getInstance()->getWorld()->isCubeVisible(p,q,r))//abs_x, abs_y, abs_z))
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
        
                Octree::bufferizeEntry(scene, getLeaf(), p/Chunk::subsize, q/Chunk::subsize, r/Chunk::subsize, ao);
                
                ao[0] = 0;
                ao[1] = 0;
                ao[2] = 0;
                ao[3] = 0;
            }
        }
    }
}