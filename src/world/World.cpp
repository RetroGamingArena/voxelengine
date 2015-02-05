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
#include <iostream>

int World::size=1;

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

void World::bufferizeEntry(GlobalBuffer* buffer, unsigned char type, float p, float q, float r, float width)
{
    float ao = 0;
    
    buffer->getData()->push_back(p);
    buffer->getData()->push_back(q);
    buffer->getData()->push_back(r);
    
    buffer->getData()->push_back(type);
    
    buffer->getData()->push_back(width);
    
    buffer->getData()->push_back(ao);
    
    return;
}

unsigned char World::getCube(int x, int y, int z)
{
    int abs_x = x+size*Chunk::size*Chunk::subsize;
     
    int abs_y = y+size*Chunk::size*Chunk::subsize;
     
    int abs_z = z+size*Chunk::size*Chunk::subsize;
    
    int p = abs_x / (Chunk::size*Chunk::subsize);
    int q = abs_y / (Chunk::size*Chunk::subsize);
    int r = abs_z / (Chunk::size*Chunk::subsize);
    
    Chunk* chunk;
    if(size == 0)
        chunk = chunks[0];
    else
        chunk = chunks[ (p)*( (size)*2+1) + r ];
    
    int sx = abs_x % (Chunk::size*Chunk::subsize);
    int sy = abs_y % (Chunk::size*Chunk::subsize);
    int sz = abs_z % (Chunk::size*Chunk::subsize);
    
    if(chunk != NULL)
    {
        return chunk->getOctree()->getAbs(sx, sy, sz, Octree::size);
    }
    
    return 0;
}

bool World::isCubeVisible(int x, int y, int z, int size)
{
    int absSize = Chunk::size*Chunk::subsize*World::size;
    
    if( x==-absSize || z==-absSize || (x+size-1)==(absSize+Chunk::size*Chunk::subsize-1) || (y+size-1)==(absSize+Chunk::size*Chunk::subsize-1) || (z+size-1)==(absSize+Chunk::size*Chunk::subsize-1) )
        return true;
    
    if( y==0 && x>-absSize && z>-absSize && (x+size-1)<(absSize+Chunk::size*Chunk::subsize-1) && (z+size-1)<(absSize+Chunk::size*Chunk::subsize-1) )
        return false;

    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
        {
            if(this->getCube(x-1, y+i,   z+j) == 0)
                return true;
            if(this->getCube((x+size-1)+1, y+i,   z+j) == 0)
                return true;
            if(this->getCube(x+i, y-1,   z+j) == 0)
                return true;
            if(this->getCube(x+i, (y+size-1)+1,   z+j) == 0)
                return true;
            if(this->getCube(x+i, y+j,   z-1) == 0)
                return true;
            if(this->getCube(x+i, y+j,   (z+size-1)+1) == 0)
                return true;
        }
    
    return false;
}