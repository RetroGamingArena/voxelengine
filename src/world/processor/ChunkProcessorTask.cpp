//
//  ChunkProcessorTask.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 03/02/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include "ChunkProcessorTask.h"

void ChunkProcessorTask::run()
{
    chunk->bufferize(chunk->getBuffer());
}