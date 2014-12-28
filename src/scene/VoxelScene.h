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
        VoxelScene(GLFWwindow* window) : VBOScene(window){}
};

#endif /* defined(__Voxelengine__VoxelScene__) */
