//
//  Node.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 26/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include <math.h>

#include "Node.h"

void Node::split()
{
    //this->entries = new OctreeEntry*[8];
    for(int i = 0; i < 8; i++)
    {
        this->entries.push_back(NULL);
    }
}

OctreeEntry* Node::get(int x, int y, int z)
{
    if(this->entries.size() > 0 )
        return this->entries[x+y*4+z*2];
    else
        return 0;
}

OctreeEntry* Node::addAndGet(int x, int y, int z, bool leaf)
{
    OctreeEntry* entry;

    if( this->entries[x+y*4+z*2] == NULL)
    {
        if(leaf)
        {
            Leaf* leaf = new Leaf();
            entry = leaf;
        }
        else
        {
            entry = new Node();
        }
        this->entries[x+y*4+z*2] = entry;
    }
    
    return this->entries[x+y*4+z*2];
}

void Node::setCube(int x, int y, int z, int size, unsigned char type)
{
    if(this->entries.size() == 0)
        this->split();
    
    int subsize = size >> 1;
    
    int i = !!(x & subsize);
    int j = !!(y & subsize);
    int k = !!(z & subsize);
    
    int _log = log2(subsize);
    
    int offset_x = x - (i << _log);
    int offset_y = y - (j << _log);
    int offset_z = z - (k << _log);
    
    OctreeEntry* entry = this->addAndGet(i,j,k, size==2);
    entry->setCube(offset_x,offset_y,offset_z, size/2, type);
    if(entry->isCompressible())
        compress(i,j,k, type);
}

void Node::compress(int x, int y, int z, unsigned char type)
{
    OctreeEntry* entry = this->get(x,y,z);
    Leaf* leaf = new Leaf();
    leaf->setLeaf(type);
    entries[x+y*4+z*2] = leaf;
    delete entry;
}

unsigned char Node::getAbs(int x, int y, int z, int size)
{
    if(this->entries.size() == 0)
        this->split();
    
    int subsize = size >> 1;
    
    int i = !!(x & subsize);
    int j = !!(y & subsize);
    int k = !!(z & subsize);
    
    int _log = log2(subsize);
    
    int offset_x = x - (i << _log);
    int offset_y = y - (j << _log);
    int offset_z = z - (k << _log);
    
    OctreeEntry* entry = this->get(i,j,k);
    if(entry == NULL)
        return 0;
    else
        return entry->getAbs(offset_x,offset_y,offset_z, size/2);
}

void Node::bufferize(GlobalBuffer* buffer, float p, float q, float r, int size)
{
    for(int i = 0; i < 8; i++)
    {
        int x = (i%4)%2;
        int y = i/4;
        int z = (i%4)/2;
        
        //bufferize(scene, this->entries[i], p+x*size/2.0, q+y*size/2.0, r+z*size/2.0, size/2.0);
        if(this->entries[i] != NULL)
            this->entries[i]->bufferize(buffer, p+x*size/2.0, q+y*size/2.0, r+z*size/2.0, size/2.0);
    }
}

void Node::invalidate()
{
    //this->drawn = 0;
    if( entries.size() == 0 )
        for(int i = 0 ; i < 8; i++)
            if(entries[i] != NULL)
                entries[i]->invalidate();
}

bool Node::isCompressible()
{
    if(entries[0] == NULL)
        return false;
    int code = entries[0]->getCode();
    if(code == NODE)
        return false;
    for( int i = 1 ; i < entries.size(); i++ )
    {
        if(entries[i]== NULL)
            return false;
        if(entries[0]->getCode() == NODE)
            return false;
        if(entries[i]->getCode() != code)
            return false;
    }
    return true;
}

void Node::generate(WorldGenerator* generator, int p, int q, int r, int size)
{
    if(this->entries.size() == 0)
        this->split();
    
    for(int i = 0; i < 8; i++)
    {
        int x = (i%4)%2;
        int y = i/4;
        int z = (i%4)/2;
        
        if(this->entries[i] == NULL)
            if(size == 1)
                entries[i] = new Leaf();
            else
                entries[i] = new Node();
        this->entries[i]->generate(generator, p+x*size/2.0, q+y*size/2.0, r+z*size/2.0, size/2.0);
    }
}