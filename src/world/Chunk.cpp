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
    float pp = p * Chunk::size * Cube::size;
    float qq = q * Chunk::size * Cube::size;
    float rr = r * Chunk::size * Cube::size;
    
    for(int i=0; i < cubes.size() ; i++)
    {
        cubes[i]->bufferize(scene, pp, qq, rr);
    }
}

void Chunk::generate(WorldGenerator* generator)
{
    float pp = p * Chunk::size * Cube::size;
    float rr = r * Chunk::size * Cube::size;

    for(int i = 0; i < size; i++)
        for(int k = 0; k < size; k++)
        {
            float height = generator->getY(pp+i, rr+k);
            
            for(int j = 0; j <= height; j++)
            {
                Cube* cube = new Cube(i, j, k);
                cube->setType(1);
                cubes.push_back(cube);
            }
        }
}