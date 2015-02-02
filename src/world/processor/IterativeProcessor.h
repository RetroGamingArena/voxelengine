//
//  IterativeProcessor.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 15/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#ifndef __Voxelengine__IterativeProcessor__
#define __Voxelengine__IterativeProcessor__

#include <stdio.h>

#include "WorldProcessor.h"
#include "../../thread/Pool.h"

class World;

class IterativeProcessor : public WorldProcessor, public Pool
{
    public:
        void bufferize(VBOScene* scene, World* world);
        Task* buildTask();
        bool hasNext();
};

#endif /* defined(__Voxelengine__IterativeProcessor__) */
