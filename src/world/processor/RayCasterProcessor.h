//
//  RayCasterProcessor.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 15/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#ifndef __Voxelengine__RayCasterProcessor__
#define __Voxelengine__RayCasterProcessor__

#include <stdio.h>

#include "WorldProcessor.h"

class RayCasterProcessor : public WorldProcessor
{
    public:
        void bufferize(VBOScene* scene, World* world);
};

#endif /* defined(__Voxelengine__RayCasterProcessor__) */
