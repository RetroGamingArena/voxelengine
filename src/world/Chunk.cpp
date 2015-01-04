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
        if(cubes[i] != NULL && cubes[i]->getType() > 0)
            cubes[i]->bufferize(scene, pp, qq, rr);
    }
}

void Chunk::generate(WorldGenerator* generator)
{
    float pp = p * Chunk::size * Cube::size;
    float rr = r * Chunk::size * Cube::size;

    //cubes.resize(size*size*size);
    
    for(int i = 0; i < size; i++)
        for(int k = 0; k < size; k++)
        {
            float height = generator->getY(pp+i, rr+k);
            
            for(int j = 0; j <= height; j++)
            {
                Cube* cube = new Cube(i, j, k);
                
                if(j<16)
                    cube->setType(2); //dirt
                else if(j<18)
                    cube->setType(3); //sand
                else if(j<20)
                    cube->setType(1); //grass
                else if(j<25)
                    cube->setType(4); //dirt
                else if(j<28)
                    cube->setType(5); //rock
                else
                    cube->setType(6); //snow
                
                //cubes[Cube::getIndex(i, j, k)] = cube;
                cubes.push_back(cube);
            }
            /*for(int j = height; j < size; j++)
            {
                Cube* cube = new Cube(i, j, k);
                cube->setType(0);
                cubes[Cube::getIndex(i, j, k)] = cube;
            }*/
        }
}

bool Chunk::isCubeVisible()
{
    return true;
}