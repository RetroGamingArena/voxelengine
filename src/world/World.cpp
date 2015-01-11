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
    /*for(int x = 0; x < 1024; x++)
        for(int y = 0; y < 768; y++)
        {
            glm::vec3 mouse3D = scene->getCamera()->unproject(x, y);
            unsigned char type = getPointedCube(mouse3D.x, mouse3D.y, mouse3D.z);
            if (type > 0)
            {
                
            }
        }*/
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

unsigned char World::getPointedCube(int x, int y, int z)
{
    for(int i=0; i < chunks.size() ; i++)
    {
        if( chunks[i]->contains(x, y, z) )
        {
            unsigned char type = chunks[i]->getOctree()->getAbs(x,y,z, Chunk::size);
            return type;
        }
    }
    return 0;
}