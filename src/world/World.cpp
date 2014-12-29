//
//  World.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 28/12/2014.
//  Copyright (c) 2014 RGA. All rights reserved.
//

#include "World.h"

void World::bufferize(VBOScene* scene)
{
    for(int i=0; i < chunks.size() ; i++)
    {
        chunks[i]->bufferize(scene);
    }
}

int World::cubeCount()
{
    int res = 0;
    for(int i=0; i < chunks.size() ; i++)
    {
        res += chunks[i]->getCubes().size();
    }
    return res;
}