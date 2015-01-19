//
//  Ray.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 18/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include "Ray.h"

glm::vec3 Ray::getNormalizedPoint()
{
    glm::vec3 d = (direction - start);
    d*=1000;
    return d;
}

glm::vec3 Ray::move(int i)
{
    glm::vec3 d = getNormalizedPoint();
    d *= i;
    d = d + direction;
    return d;
}