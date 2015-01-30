//
//  Leaf.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 25/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include "Leaf.h"

void Leaf::invalidate()
{
    //this->drawn = 0;
}

void Leaf::setCube(int x, int y, int z, int size, unsigned char type)
{
    this->leaf = type;
}