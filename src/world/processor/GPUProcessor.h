//
//  GPUProcessor.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 15/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#ifndef __Voxelengine__GPUProcessor__
#define __Voxelengine__GPUProcessor__

#include <stdio.h>

#include "WorldProcessor.h"

#endif /* defined(__Voxelengine__GPUProcessor__) */

class GPUProcessor : public WorldProcessor
{
    public:
        void bufferize(VBOScene* scene, World* world);
};