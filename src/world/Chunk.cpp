//
//  Chunk.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 29/12/2014.
//  Copyright (c) 2014 RGA. All rights reserved.
//

#include "Chunk.h"
#include "CubeType.h"

#include <algorithm>

int Chunk::size = 16;
int Chunk::subsize = 16;

void Chunk::bufferize(GlobalBuffer* buffer)
{
    float pp = p * Chunk::size * Cube::size;
    float qq = q * Chunk::size * Cube::size;
    float rr = r * Chunk::size * Cube::size;
    
    o->bufferize(buffer, 0, 0, 0);
}

void Chunk::generate(WorldGenerator* generator)
{
    float pp = p * Chunk::size * Chunk::subsize * Cube::size;
    float rr = r * Chunk::size * Chunk::subsize * Cube::size;
    
    unsigned char type = 0;
    unsigned char* types = new unsigned char[8];
    
    for(float i = 0; i < size*subsize; i+=2)
        for(float k = 0; k < size*subsize; k+=2)
        {
            float height1 = generator->getY(pp+i, rr+k)*size*subsize/2;
            float height=1;
            float height2 = generator->getY(pp+i+1, rr+k)*size*subsize/2;
            height = max(height,height2);
            float height3 = generator->getY(pp+i, rr+k+1)*size*subsize/2;
            height = max(height,height3);
            float height4 = generator->getY(pp+i+1, rr+k+1)*size*subsize/2;
            height = max(height,height4);
            height++;

            for(int j = 0; j <= height; j+=2)
            {
                type = CubeType::getTypeFromHeight(j);
                
                for(int i = 0; i< 8; i++)
                {
                    types[i] = 0;
                }
                
                if(j<height1)
                    types[0] = type;
                if(j+1<height1)
                    types[4] = type;
                
                if(j<height2)
                    types[1] = type;
                if(j+1<height2)
                    types[5] = type;
                
                if(j<height3)
                    types[2] = type;
                if(j+1<height3)
                    types[6] = type;
                
                if(j<height4)
                    types[3] = type;
                if(j+1<height4)
                    types[7] = type;

                o->setCubes(i,   j,   k, size*subsize, types);
            }
        }
    delete[] types;
}

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