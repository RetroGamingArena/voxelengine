//
//  CubeType.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 02/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include "CubeType.h"
#include "Chunk.h"

glm::vec3 CubeType::getColor(unsigned char type, int y)
{
    //y = Chunk::size;
    
    glm::vec3 res;
    switch(type)
    {
        case 1:
            res.r = 0;
            res.g = y/(float)Chunk::size;
            res.b = 0;
            break;
        case 2:
            res.r = 0;
            res.g = 0;
            res.b = y/(float)Chunk::size;
            break;
        case 3:
            res.r = y/(float)Chunk::size;
            res.g = y/(float)Chunk::size;
            res.b = 0;
            break;
        case 4:
            res.r = 1-y/(float)Chunk::size;
            res.g = 1-y/(float)Chunk::size;
            res.b = 0;
            break;
        case 5:
            res.r = 1-y/(float)Chunk::size;
            res.g = 1-y/(float)Chunk::size;
            res.b = 1-y/(float)Chunk::size;
            break;
        case 6:
            res.r = 1;
            res.g = 1;
            res.b = 1;
            break;
        default:
            break;
    }
    return res;
}

glm::vec3 CubeType::getColor(Cube* cube)
{
    glm::vec3 res;
    switch(cube->getType())
    {
        case 1:
            res.r = 0;
            res.g = cube->getY()/(float)Chunk::size;
            res.b = 0;
            break;
        case 2:
            res.r = 0;
            res.g = 0;
            res.b = cube->getY()/(float)Chunk::size;
            break;
        case 3:
            res.r = cube->getY()/(float)Chunk::size;
            res.g = cube->getY()/(float)Chunk::size;
            res.b = 0;
            break;
        case 4:
            res.r = 1-cube->getY()/(float)Chunk::size;
            res.g = 1-cube->getY()/(float)Chunk::size;
            res.b = 0;
            break;
        case 5:
            res.r = 1-cube->getY()/(float)Chunk::size;
            res.g = 1-cube->getY()/(float)Chunk::size;
            res.b = 1-cube->getY()/(float)Chunk::size;
            break;
        case 6:
            res.r = 1;
            res.g = 1;
            res.b = 1;
            break;
        default:
            break;
    }
    return res;
}