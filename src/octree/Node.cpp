//
//  Node.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 26/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include "Node.h"
#include "Leaf.h"

void Node::split()
{
    this->entries = new OctreeEntry*[8];
    for(int i = 0; i < 8; i++)
    {
        this->entries[i] = new Node();
        //this->entries[i]->setLevel(level+1);
        //this->entries[i]->leaf = 0;
    }
}

OctreeEntry* Node::get(int x, int y, int z)
{
    return this->entries[x+y*4+z*2];
}

void Node::setCube(int x, int y, int z, int size, unsigned char type)
{
    if(this->entries == NULL)
        this->split();
    
    if(size==1)
    {
        delete this->entries[x+y*4+z*2];
        
        Leaf* leaf = new Leaf();
        leaf->setLeaf(type);
        this->entries[x+y*4+z*2] = leaf;
        
        //this->entries[x+y*4+z*2]->leaf = type;
        return;
    }
    
    int i = !!(x & size/2);
    int j = !!(y & size/2);
    int k = !!(z & size/2);
    
    int offset_x = x - i * (size/2);
    int offset_y = y - j * (size/2);
    int offset_z = z - k * (size/2);
    
    Node* node = dynamic_cast<Node*>(this->get(i,j,k));
    
    if(node != NULL)
    {
        if(size==2)
            /*this->get(i,j,k)*/node->setCube(i,j,k, 1, type);
        else
            /*this->get(i,j,k)*/node->setCube(offset_x,offset_y,offset_z, size/2, type);
    }
}

OctreeEntry* Node::getAbs(int x, int y, int z, int size)
{
    if(this->entries == NULL)
        return 0;
    
    if(size==1)
        return this->entries[x+y*4+z*2];
    
    int ii = !!(x & size/2);
    int jj = !!(y & size/2);
    int kk = !!(z & size/2);
    
    int offset_x = x - ii * (size/2);
    int offset_y = y - jj * (size/2);
    int offset_z = z - kk * (size/2);
    
    Node* node = dynamic_cast<Node*>(this->get(ii,jj,kk));
    
    if(size==2)
        return /*this->get(ii,jj,kk)*/node->getAbs(ii,jj,kk, 1);
    else
        return /*this->get(ii,jj,kk)*/node->getAbs(offset_x,offset_y,offset_z, size/2);
}

void Node::invalidate()
{
    //this->drawn = 0;
    if( entries != NULL )
        for(int i = 0 ; i < 8; i++)
            if(entries[i] != NULL)
                entries[i]->invalidate();
}