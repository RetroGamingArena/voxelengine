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
    this->entries = new OctreeEntry*[8];
    for(int i = 0; i < 8; i++)
    {
        this->entries[i] = NULL;
    }
}

OctreeEntry* Node::get(int x, int y, int z)
{
    return this->entries[x+y*4+z*2];
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
    
    return this->entries[x+y*4+z*2];//get(x, y, z);
}

bool Node::isCompressible()
{
    if(entries == NULL)
        return false;
    if(entries[0] == NULL)
        return false;
    Leaf* leaf = dynamic_cast<Leaf*>(entries[0]);
    if(leaf == NULL)
        return false;
    unsigned char type = leaf->getLeaf();
    for(int i = 1; i < 8; i++)
    {
        leaf = dynamic_cast<Leaf*>(entries[i]);
        if(leaf == NULL)
            return false;
        if(leaf->getLeaf() != type)
            return false;
    }
    return true;
}

void Node::setCube(int x, int y, int z, int size, unsigned char type)
{
    if(this->entries == NULL)
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
}

Leaf* Node::getAbs(int x, int y, int z, int size)
{
    if(this->entries == NULL)
        return 0;
    
    //if(size==1)
    //    return this->entries[x+y*4+z*2];
    
    int ii = !!(x & size/2);
    int jj = !!(y & size/2);
    int kk = !!(z & size/2);
    
    int offset_x = x - ii * (size/2);
    int offset_y = y - jj * (size/2);
    int offset_z = z - kk * (size/2);
    
    Node* node = dynamic_cast<Node*>(this->get(ii,jj,kk));
    
    if( node == NULL )
    {
        Leaf* leaf = dynamic_cast<Leaf*>(this->get(ii,jj,kk));
        return leaf;
    }
    
    if(size==2)
    {
        return node->getAbs(ii,jj,kk, 1);
    }else
        return node->getAbs(offset_x,offset_y,offset_z, size/2);
}

void Node::bufferize(VBOScene* scene, float p, float q, float r, int size)
{
    for(int i = 0; i < 8; i++)
    {
        int x = (i%4)%2;
        int y = i/4;
        int z = (i%4)/2;
        
        //bufferize(scene, this->entries[i], p+x*size/2.0, q+y*size/2.0, r+z*size/2.0, size/2.0);
        if(this->entries[i] != NULL)
            this->entries[i]->bufferize(scene, p+x*size/2.0, q+y*size/2.0, r+z*size/2.0, size/2.0);
    }
}

void Node::invalidate()
{
    //this->drawn = 0;
    if( entries != NULL )
        for(int i = 0 ; i < 8; i++)
            if(entries[i] != NULL)
                entries[i]->invalidate();
}