//
//  Chunk.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 29/12/2014.
//  Copyright (c) 2014 RGA. All rights reserved.
//

#include "Chunk.h"

#include <algorithm>

int Chunk::size = 2;
int Chunk::subsize = 32;

void Chunk::bufferize(VBOScene* scene)
{
    float pp = p * Chunk::size * Cube::size;
    float qq = q * Chunk::size * Cube::size;
    float rr = r * Chunk::size * Cube::size;
    
    /*for(int i=0; i < cubes.size() ; i++)
    {
        if( cubes[i] != NULL && cubes[i]->getType() > 0 && isCubeVisible(Cube::getIndex(cubes[i]->getX(), cubes[i]->getY(), cubes[i]->getZ() )))
        {
            cubes[i]->bufferize(scene, pp, qq, rr);
        }
    }*/
    
    o->bufferize(scene, 0, 0, 0);//pp, qq, rr);
    delete o;
}

void Chunk::generate(WorldGenerator* generator)
{
    float pp = p * Chunk::size * Chunk::subsize * Cube::size;
    float rr = r * Chunk::size * Chunk::subsize * Cube::size;

    for(float i = 0; i < size*subsize; i+=1)
        for(float k = 0; k < size*subsize; k+=1)
        {
            float height = generator->getY(pp+i, rr+k)*size*subsize/2;
            
            for(int j = 0; j <= height; j++)
            {
                unsigned char type;
                
                if(j<16*size*subsize/32)
                    type = 2; //dirt
                else if(j<18*size*subsize/32)
                    type = 3; //sand
                else if(j<20*size*subsize/32)
                    type = 1; //grass
                else if(j<25*size*subsize/32)
                    type = 4; //dirt
                else if(j<28*size*subsize/32)
                    type = 5; //rock
                else
                    type = 6; //snow
                o->setCube(i,j,k, size*subsize, type);
            }
        }
}

/*bool Chunk::isCubeVisible(int index)
{
    glm::vec3 coords = Cube::getCoords(index);
    
    int x = coords.x;
    int y = coords.y;
    int z = coords.z;
    
    if( x==0 || y==0 || z==0 || x==(size-1) || y==(size-1) || z==(size-1) )
        return true;
    
    try
    {
        bool test = !(indexedCubes.at(Cube::getIndex(x-1, y,   z)) != 0 && indexedCubes.at(Cube::getIndex(x+1, y,   z)) != 0
                      && indexedCubes.at(Cube::getIndex(x,   y-1, z)) != 0
                      && indexedCubes.at(Cube::getIndex(x,   y+1, z)) != 0
                      && indexedCubes.at(Cube::getIndex(x,   y,   z-1)) != 0
                      && indexedCubes.at(Cube::getIndex(x,   y,   z+1)) != 0);
        return test;
    }
    catch(out_of_range e)
    {
        return true;
    }
    return true;
}*/

bool Chunk::contains(float x, float y, float z)
{
    bool res = ( this->p * size <= x && x < (this->p * size + size) &&
                 this->q * size <= y && y < (this->q * size + size) &&
                 this->r * size <= z && z < (this->r * size + size) );
    if(res == true)
    {
        int a = 2;
    }
    return res;
}