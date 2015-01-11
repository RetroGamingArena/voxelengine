//
//  OctreeEntry.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 07/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include "OctreeEntry.h"

/*template<typename T>
void OctreeEntry<T>::init()
{
    this->nodes = new T*[2];
    
    this->nodes[0] = new T[2];
    this->nodes[1] = new T[2];
}*/

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
void OctreeEntry<T>::setCube(int x, int y, int z, int size, unsigned char type)
{
    if(this->entries == NULL)
        this->split();

    if(size==1)
    {
        this->entries[x+y*4+z*2]->leaf = type;
        return;
    }
    
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
            {
                if(   (i * (size / 2) <= x && x < (i+1) * (size / 2))
                    && (j * (size / 2) <= y && y < (j+1) * (size / 2))
                    && (k * (size / 2) <= z && z < (k+1) * (size / 2))
                    )
                {
                    int offset_x = x - i * (size/2);
                    int offset_y = y - j * (size/2);
                    int offset_z = z - k * (size/2);
                    
                    //offset_y == 4
                    
                    if(size==2)
                        this->get(i,j,k)->setCube(i,j,k, 1, type);
                    else
                        this->get(i,j,k)->setCube(offset_x,offset_y,offset_z, size/2, type);
                }
            }
}

template<typename T>
OctreeEntry<T>* OctreeEntry<T>::getAbs(int x, int y, int z, int size)
{
    if(this->entries == NULL)
        return 0;
    
    if(size==1)
    {
        TemplateDebug::debug();
        return this->entries[x+y*4+z*2];
    }
    
    for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++)
    for(int k = 0; k < 2; k++)
    {
        if(   (i * (size / 2) <= x && x < (i+1) * (size / 2))
           && (j * (size / 2) <= y && y < (j+1) * (size / 2))
           && (k * (size / 2) <= z && z < (k+1) * (size / 2))
           )
        {
            int offset_x = x - i * (size/2);
            int offset_y = y - j * (size/2);
            int offset_z = z - k * (size/2);
            
            //offset_y == 4
            
            if(size==2)
                return this->get(i,j,k)->getAbs(i,j,k, 1);
            else
                return this->get(i,j,k)->getAbs(offset_x,offset_y,offset_z, size/2);
        }
    }
    return 0;
}