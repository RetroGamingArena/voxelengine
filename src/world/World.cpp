//
//  World.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 28/12/2014.
//  Copyright (c) 2014 RGA. All rights reserved.
//

#include "World.h"

int World::size=0;

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
        //res += chunks[i]->getCubes().size();
    }
    return res;
}

glm::vec3 World::getPointedCube()
{
    for(int i=0; i < chunks.size() ; i++)
    {
        //chunks[i]->
    }
    
    return glm::vec3(0,0,0);
}