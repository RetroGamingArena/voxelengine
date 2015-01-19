//
//  Ray.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 18/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#ifndef __Voxelengine__Ray__
#define __Voxelengine__Ray__

#include <stdio.h>

#include "../../depends/glm/glm.hpp"
#include "../../depends/glm/gtc/matrix_transform.hpp"

class Ray
{
    glm::vec3 start;
    glm::vec3 direction;

    public:
        Ray(glm::vec3 start, glm::vec3 direction)
        {
            this->start = start;
            this->direction = direction;
        }
        glm::vec3 getNormalizedPoint();
        glm::vec3 move(int i);
};

#endif /* defined(__Voxelengine__Ray__) */
