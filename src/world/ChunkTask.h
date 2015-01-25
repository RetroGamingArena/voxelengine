//
//  ChunkTask.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 25/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#ifndef __Voxelengine__ChunkTask__
#define __Voxelengine__ChunkTask__

#include <stdio.h>

#include "../thread/Task.h"
#include "Chunk.h"

class ChunkTask : public Task
{
    Chunk* chunk;
    WorldGenerator* generator;

    public:
        ChunkTask(Chunk* chunk, WorldGenerator* generator)
        {
            this->chunk = chunk;
            this->generator = generator;
        }
        void run();
};

#endif /* defined(__Voxelengine__ChunkTask__) */
