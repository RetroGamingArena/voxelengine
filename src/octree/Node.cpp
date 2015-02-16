//
//  Node.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 26/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include <math.h>

#include "Node.h"
#include "../world/Chunk.h"
#include "../world/World.h"

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
    if( this->entries[x+y*4+z*2] == NULL)
    {
        OctreeEntry* entry;
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

void Node::setCubes(int x, int y, int z, int size, unsigned char* types)
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
    
    if(size==4)
    {
        if( types[0] == types[1] && types[1] == types[2] && types[2] == types[3] && types[3] == types[4] && types[4] == types[5] && types[5] == types[6] && types[6] == types[7] )
        {
            entries[i+j*4+k*2] = new Leaf(types[0]);
            return;
        }
    }
    if(size == 2)
    {
        for(int i=0;i<8;i++)
            entries[i] = new Leaf(types[i]);
    }
    else
    {
        OctreeEntry* entry = this->addAndGet(i,j,k, size==2);
        entry->setCubes(offset_x,offset_y,offset_z, size>>1, types);
        if(entry->isCompressible())
            compress(i,j,k, types[0]);
    }
    //if(entry->isCompressible())
    //    compress(i,j,k, type);
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
    entry->setCube(offset_x,offset_y,offset_z, size>>1, type);
    if(entry->isCompressible())
        compress(i,j,k, type);
}

void Node::compress(int x, int y, int z, unsigned char type)
{
    OctreeEntry* entry = this->get(x,y,z);
    
    type = entry->getAbs(x, y, z, 4);
    
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

OctreeEntry* Node::getOctreeEntryAbs(int x, int y, int z, int size)
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
    if(size == 1)
        return entry;
    else
        return entry->getOctreeEntryAbs(offset_x,offset_y,offset_z, size>>1);
    //if(entry->isCompressible())
    //    compress(i,j,k, type);
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
    int absSize = 0;
    
    float size_2 = size >> 1;
    
    for(int i = 0; i < 8; i++)
    {
        int x = (i%4)&1;
        int y = i >> 2;
        int z = (i%4) >> 1;
        
        if(this->entries[i] == NULL)
        {
            int ii;
            if(size == 2)
            {
                float height = generator->getY(p+x*size_2, r+z*size_2)*Chunk::size*Chunk::subsize/2;
                if( q+y*size_2 <= height )
                {
                    entries[i] = new Leaf();
                    entries[i]->generate(generator, p+x*size_2, q+y*size_2, r+z*size_2, size_2);
                    
                    if(this->entries[i]->isCompressible())
                        compress(x,y,z, 1);
                }
            }
            else
            {
                for(ii = 0; ii < (size_2)*(size_2); ii++)
                {
                    int j = ii / (size_2);
                    int k = ii % (int)(size_2);

                    float height = generator->getY(absSize+p+x*size_2+j, absSize+r+z*size_2+k)*Chunk::size*Chunk::subsize/2;
                    if (height < (q+size*(y+1)/2))
                    {
                        entries[i] = new Node();
                        this->entries[i]->generate(generator, p+x*size_2, q+y*size_2, r+z*size_2, size_2);
                        if(this->entries[i]->isCompressible())
                            compress(x,y,z, 1);
                        break;
                    }
                    
                }
            
                if(ii == size_2*size_2)
                {
                    entries[i] = new Leaf();
                    entries[i]->generate(generator, p+x*size_2, q+y*size_2, r+z*size_2, size_2);
                   
                    if(this->entries[i]->isCompressible())
                        compress(x,y,z, 1);
                }
            }
        }
    }
}