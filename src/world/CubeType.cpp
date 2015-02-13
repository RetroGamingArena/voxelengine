//
//  CubeType.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 02/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include "CubeType.h"
#include "Chunk.h"

unsigned char CubeType::getTypeFromHeight(int height)
{
    unsigned char type;
    if(height<16*Chunk::size*Chunk::subsize/32)
        type = 2; //dirt
    else if(height<18*Chunk::size*Chunk::subsize/32)
        type = 3; //sand
    else if(height<20*Chunk::size*Chunk::subsize/32)
        type = 1; //grass
    else if(height<25*Chunk::size*Chunk::subsize/32)
        type = 4; //dirt
    else if(height<28*Chunk::size*Chunk::subsize/32)
        type = 5; //rock
    else
        type = 6; //snow
    return type;
}