//
//  PerlinGenerator.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 02/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include "PerlinGenerator.h"
#include "../Chunk.h"

float PerlinGenerator::getY(float x, float y)
{
    int absBound = (destSize/Chunk::size)/2;
    float height = heightMap.GetValue(x+absBound*Chunk::size, y+absBound*Chunk::size);
    if(height < -1)
        height = -1;
    if(height >= 1)
        height = 0.99999;
    return (height+1);
}