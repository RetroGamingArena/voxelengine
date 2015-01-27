//
//  World.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 28/12/2014.
//  Copyright (c) 2014 RGA. All rights reserved.
//

#include "World.h"
#include "Octree.h"
#include "../thread/Task.h"
#include "ChunkTask.h"

int World::size=0;

void World::bufferize(VBOScene* scene)
{
    //processor->bufferize(scene, this);
    
    /*float* ao = new float[4];
    
    glm::vec3 position = scene->getCamera()->getPosition();
    
    for(int i=0; i < (size*2+1)*(size*2+1) ; i++)
        this->chunks[i]->getOctree()->invalidate();
    
    for(int x = 0; x < 1024; x=x+1)
        for(int y = 0; y < 768; y=y+1)
        {
            glm::vec3 mouse3D = scene->getCamera()->unproject(x, y);
            
            float dx = (mouse3D.x - position.x) * 1000;
            float dy = (mouse3D.y - position.y) * 1000;
            float dz = (mouse3D.z - position.z) * 1000;
            
            for(int i = 0; i < 120; i=i+1)
            {
                float xx = dx * i + mouse3D.x;
                float yy = dy * i + mouse3D.y;
                float zz = dz * i + mouse3D.z;
                
                OctreeEntry<unsigned char>* octreeEntry = getPointedCube(xx, yy, zz);
                if( octreeEntry == NULL)
                    continue;
                if( octreeEntry->isDrawn() )
                    break;
                unsigned char type = octreeEntry->getLeaf();
                if(type > 0)
                {
                    Octree<unsigned char>::bufferizeEntry(scene, type, (int)xx, (int)yy, (int)zz, ao);
                    octreeEntry->setDrawn(true);
                    break;
                }
            }
        }*/
    
    /*for(int i=0; i < chunks.size() ; i++)
    {
        chunks[i]->bufferize(scene);
    }*/
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

Chunk* World::getPointedChunk(float x, float y, float z)
{
    for(int i=0; i < chunks.size(); i++)
    {
        if( chunks[i]->contains(x, y, z) )
        {
            return chunks[i];
        }
    }
    return 0;
}

OctreeEntry* World::getPointedCube(float x, float y, float z)
{
    for(int i=0; i < chunks.size(); i++)
    {
        if( chunks[i]->contains(x, y, z) )
        {
            return 0; //chunks[i]->getOctree()->getAbs(x,y,z, Chunk::size)->getEntries()[0];
        }
    }
    return 0;
}

Task* World::buildTask()
{
    if( mutex->try_lock() && hasNext())
    {
        Chunk* chunk = chunks[chunkIndice];
        ChunkTask* chunkTask = new ChunkTask(chunk, generator);
        chunkIndice = chunkIndice+1;
        mutex->unlock();
        return chunkTask;
    }
    return NULL;
}

bool World::hasNext()
{
    return chunkIndice < chunks.size();
}