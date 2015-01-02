//
//  PerlinGenerator.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 02/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include "PerlinGenerator.h"

float PerlinGenerator::getY(float x, float y)
{
    return (heightMap.GetValue(x, y)+1)*2;
}