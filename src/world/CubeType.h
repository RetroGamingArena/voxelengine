//
//  CubeType.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 02/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#ifndef __Voxelengine__CubeType__
#define __Voxelengine__CubeType__

#include <stdio.h>

#include "../../depends/glm/glm.hpp"
#include "../../depends/glm/gtc/matrix_transform.hpp"
#include "Cube.h"

class CubeType
{
    public:
        static glm::vec3 getColor(Cube* cube);
    static glm::vec3 getColor(unsigned char type, int y);
};

#endif /* defined(__Voxelengine__CubeType__) */
