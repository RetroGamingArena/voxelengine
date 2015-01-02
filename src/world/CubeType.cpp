//
//  CubeType.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 02/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include "CubeType.h"
#include "Chunk.h"

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
        default:
            break;
    }
    return res;
}