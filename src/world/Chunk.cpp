//
//  Chunk.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 29/12/2014.
//  Copyright (c) 2014 RGA. All rights reserved.
//

#include "Chunk.h"

void Chunk::bufferize(VBOScene* scene)
{
    for(int i=0; i < cubes.size() ; i++)
    {
        cubes[i]->bufferize(scene);
    }
}