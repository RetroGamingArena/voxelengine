//
//  WorldProcessor.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 15/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#ifndef __Voxelengine__WorldProcessor__
#define __Voxelengine__WorldProcessor__

#include <stdio.h>

#include "../World.h"
#include "../../scene/VBOScene.h"

class WorldProcessor
{
    public:
        virtual void bufferize(VBOScene* scene, World* world) = 0;
        bool isCubeVisible(int x, int y, int z);
};

#endif /* defined(__Voxelengine__WorldProcessor__) */
