//
//  Chunk.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 29/12/2014.
//  Copyright (c) 2014 RGA. All rights reserved.
//

#include "Chunk.h"

int Chunk::size = 32;

void Chunk::bufferize(VBOScene* scene)
{
    for(int i=0; i < cubes.size() ; i++)
    {
        cubes[i]->bufferize(scene, this->p, this->q, this->r);
    }
}

void Chunk::generate(WorldGenerator* generator)
{
    for(int i = 0; i < size; i++)
        for(int k = 0; k < size; k++)
            for(int j = 0; j < generator->getY(i, k); j++)
            {
                cubes.push_back(new Cube(i, j, k));
            }
    /*cubes.push_back(new Cube(0, 0, 0));
     cubes.push_back(new Cube(1, 0, 0));
     cubes.push_back(new Cube(0, 0, 1));
     cubes.push_back(new Cube(0, 1, 0));*/
}