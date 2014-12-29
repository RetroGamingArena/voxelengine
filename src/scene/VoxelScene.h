//
//  VoxelScene.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 28/12/2014.
//  Copyright (c) 2014 RGA. All rights reserved.
//

#ifndef __Voxelengine__VoxelScene__
#define __Voxelengine__VoxelScene__

#include <stdio.h>

#include "VBOScene.h"
#include "../world/World.h"

class VoxelScene : public VBOScene
{
    public:
        VoxelScene(GLFWwindow* window) : VBOScene(window)
        {
            buffer = new GLfloat[9];
            buffer[0] = -1.0f;
            buffer[1] = -1.0f;
            buffer[2] = 0.0f;
            buffer[3] =  1.0f;
            buffer[4] = -1.0f;
            buffer[5] = 0.0f;
            buffer[6] = 0.0f;
            buffer[7] = 1.0f;
            buffer[8] = 0.0f;
            bindBuffer();
        }
};

#endif /* defined(__Voxelengine__VoxelScene__) */
