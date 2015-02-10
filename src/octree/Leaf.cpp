//
//  Leaf.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 25/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include "Leaf.h"
#include "../engine/engine.h"
#include "../world/CubeType.h"

void Leaf::invalidate()
{
    //this->drawn = 0;
}

void Leaf::setCubes(int x, int y, int z, int size, unsigned char* type)
{

}

OctreeEntry* Leaf::getOctreeEntryAbs(int x, int y, int z, int size)
{
    return this;
}

void Leaf::setCube(int x, int y, int z, int size, unsigned char type)
{
    this->leaf = type;
}

void Leaf::bufferize(GlobalBuffer* buffer, float p, float q, float r, int size)
{
    World* world = Engine::getInstance()->getWorld();
    
    if(getLeaf() > 0)
    {
        if(world->isCubeVisible(p,q,r,size))
        {        
            world->bufferizeEntry(buffer, getLeaf(), p/Chunk::subsize, q/Chunk::subsize, r/Chunk::subsize, size);
        }
    }
}

unsigned char Leaf::getAbs(int x, int y, int z, int size)
{
    return this->getLeaf();
}

void Leaf::generate(WorldGenerator* generator, int x, int y, int z, int size)
{
    float height = generator->getY(x/*pp+i*/, z/*rr+k*/)*Chunk::size*Chunk::subsize/2;
    
    if( y > height )
    {
        setLeaf(0);
        return;
    }
    
    int j = height;
    //for(int j = 0; j <= height; j++)
    {
        unsigned char type;
        
        if(j<16*Chunk::size*Chunk::subsize/32)
            type = 2; //dirt
        else if(j<18*Chunk::size*Chunk::subsize/32)
            type = 3; //sand
        else if(j<20*Chunk::size*Chunk::subsize/32)
            type = 1; //grass
        else if(j<25*Chunk::size*Chunk::subsize/32)
            type = 4; //dirt
        else if(j<28*Chunk::size*Chunk::subsize/32)
            type = 5; //rock
        else
            type = 6; //snow
        setLeaf(type);
    }
}