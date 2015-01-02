//
//  WorldGenerator.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 02/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#ifndef __Voxelengine__WorldGenerator__
#define __Voxelengine__WorldGenerator__

#include <stdio.h>

class WorldGenerator
{
    public:
        virtual float getY(float x, float y) = 0;
};

#endif /* defined(__Voxelengine__WorldGenerator__) */
