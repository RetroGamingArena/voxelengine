//
//  ChunkProcessorTask.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 03/02/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#ifndef __Voxelengine__ChunkProcessorTask__
#define __Voxelengine__ChunkProcessorTask__

#include <stdio.h>

#include "../../thread/Task.h"
#include "../Chunk.h"

class ChunkProcessorTask : public Task
{
    Chunk* chunk;

    public:
        ChunkProcessorTask(Chunk* chunk)
        {
            this->chunk = chunk;
        }
        void run();
};

#endif /* defined(__Voxelengine__ChunkProcessorTask__) */
