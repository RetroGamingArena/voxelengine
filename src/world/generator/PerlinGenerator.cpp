//
//  PerlinGenerator.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 02/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include "PerlinGenerator.h"
#include "../World.h"
#include "../Chunk.h"

float PerlinGenerator::getY(float x, float y)
{
    int absBound = World::size*Chunk::size*Chunk::subsize;//(destSize/(Chunk::size*Chunk::subsize))/2;
    float height = heightMap.GetValue(x+absBound, y+absBound);
    if(height < -1)
        height = -1;
    if(height >= 1)
        height = 0.99999;
    return (height+1);
}