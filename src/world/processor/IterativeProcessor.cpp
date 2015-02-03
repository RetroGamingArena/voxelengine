//
//  IterativeProcessor.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 15/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include "IterativeProcessor.h"
#include "../../engine/engine.h"
#include "ChunkProcessorTask.h"

void IterativeProcessor::bufferize(VBOScene* scene, World* world)
{
    int x = 0;
    int y = 0;
    int z = 0;
    
    int p = 0;
    int q = 0;
    int r = 0;
    
    float size = 1.0 / Chunk::subsize;
    
    float type = 2;
    
    float* ao = new float[4];
    
    ao[0] = 0.5;
    ao[1] = 0.5;
    ao[2] = 0.5;
    ao[3] = 0.5;
    
    Cube::bufferizeSquare(scene, x+p, y+q,      z+r, x+p+size, y+q,      z+r+size, type, ao); //bottom
    
    Cube::bufferizeIndice(scene, 0);
    Cube::bufferizeIndice(scene, 1);
    Cube::bufferizeIndice(scene, 2);
    Cube::bufferizeIndice(scene, 1);
    Cube::bufferizeIndice(scene, 2);
    Cube::bufferizeIndice(scene, 3);
    
    ao[0] = 0;
    ao[1] = 0;
    ao[2] = 0;
    ao[3] = 0;
    
    Cube::bufferizeSquare(scene, x+p, y+q+size, z+r, x+p+size, y+q+size, z+r+size, type, ao); //top
    
    Cube::bufferizeIndice(scene, 4);
    Cube::bufferizeIndice(scene, 5);
    Cube::bufferizeIndice(scene, 6);
    Cube::bufferizeIndice(scene, 5);
    Cube::bufferizeIndice(scene, 6);
    Cube::bufferizeIndice(scene, 7);
    
    Cube::bufferizeIndice(scene, 0);
    Cube::bufferizeIndice(scene, 1);
    Cube::bufferizeIndice(scene, 4);
    Cube::bufferizeIndice(scene, 1);
    Cube::bufferizeIndice(scene, 4);
    Cube::bufferizeIndice(scene, 5);
    
    Cube::bufferizeIndice(scene, 1);
    Cube::bufferizeIndice(scene, 3);
    Cube::bufferizeIndice(scene, 5);
    Cube::bufferizeIndice(scene, 3);
    Cube::bufferizeIndice(scene, 5);
    Cube::bufferizeIndice(scene, 7);
    
    Cube::bufferizeIndice(scene, 3);
    Cube::bufferizeIndice(scene, 2);
    Cube::bufferizeIndice(scene, 7);
    Cube::bufferizeIndice(scene, 2);
    Cube::bufferizeIndice(scene, 7);
    Cube::bufferizeIndice(scene, 6);
    
    Cube::bufferizeIndice(scene, 2);
    Cube::bufferizeIndice(scene, 0);
    Cube::bufferizeIndice(scene, 6);
    Cube::bufferizeIndice(scene, 0);
    Cube::bufferizeIndice(scene, 6);
    Cube::bufferizeIndice(scene, 4);
    
    threadCount = 5;
    this->start();
    while(isRunning()){}
    
    for(int i=0; i < world->getChunks().size() ; i++)
    {
        Chunk* chunk = world->getChunks()[i];
        scene->getBuffer()->getData()->insert(scene->getBuffer()->getData()->end(), chunk->getBuffer()->getData()->begin(), chunk->getBuffer()->getData()->end());
        chunk->getBuffer()->getData()->clear();
    }
}

Task* IterativeProcessor::buildTask()
{
    if( mutex->try_lock() && hasNext())
    {
        std::vector<Chunk*> chunks = Engine::getInstance()->getWorld()->getChunks();
        Chunk* chunk = chunks[chunkIndice];
        ChunkProcessorTask* chunkProcessorTask = new ChunkProcessorTask(chunk);
        chunkIndice = chunkIndice+1;
        mutex->unlock();
        return chunkProcessorTask;
    }
    return NULL;
}

bool IterativeProcessor::hasNext()
{
    World* world = Engine::getInstance()->getWorld();
    return chunkIndice < world->getChunks().size();
}