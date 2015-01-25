//
//  ChunkTask.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 25/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include "ChunkTask.h"

void ChunkTask::run()
{
    chunk->generate(generator);
}