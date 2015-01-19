//
//  OctreeEntry.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 07/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include <iostream>

#include "OctreeEntry.h"

template<typename T>
void OctreeEntry<T>::split()
{
    this->entries = new OctreeEntry<T>*[8];
    for(int i = 0; i < 8; i++)
    {
        this->entries[i] = new OctreeEntry<T>();
        this->entries[i]->setLevel(level+1);
        this->entries[i]->leaf = 0;
    }
}

template<typename T>
OctreeEntry<T>* OctreeEntry<T>::get(int x, int y, int z)
{
    return this->entries[x+y*4+z*2];
}

template<typename T>
void OctreeEntry<T>::setCube(int x, int y, int z, int size, T type)
{
    if(this->entries == NULL)
        this->split();

    if(size==1)
    {
        this->entries[x+y*4+z*2]->leaf = type;
        return;
    }
    
    int i = !!(x & size/2);
    int j = !!(y & size/2);
    int k = !!(z & size/2);
    
    int offset_x = x - i * (size/2);
    int offset_y = y - j * (size/2);
    int offset_z = z - k * (size/2);
                    
    if(size==2)
        this->get(i,j,k)->setCube(i,j,k, 1, type);
    else
        this->get(i,j,k)->setCube(offset_x,offset_y,offset_z, size/2, type);
}

template<typename T>
OctreeEntry<T>* OctreeEntry<T>::getAbs(int x, int y, int z, int size)
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
    
    if(size==2)
        return this->get(ii,jj,kk)->getAbs(ii,jj,kk, 1);
    else
        return this->get(ii,jj,kk)->getAbs(offset_x,offset_y,offset_z, size/2);
}

template<typename T>
void OctreeEntry<T>::invalidate()
{
    this->drawn = 0;
    if( entries != NULL )
        for(int i = 0 ; i < 8; i++)
            if(entries[i] != NULL)
                entries[i]->invalidate();
}