//
//  Octree.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 07/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include "Octree.h"
#include "../world/Cube.h"
#include "../world/CubeType.h"
#include "../octree/Leaf.h"

int Octree::size = 0;
float Octree::subSize = 0;

void Octree::bufferize(GlobalBuffer* buffer, float p, float q, float r) //TODO octree offset
{
    for(int i = 0; i < 8; i++)
    {
        int x = (i%4)%2;
        int y = i/4;
        int z = (i%4)/2;

            //bufferize(scene, this->entries[i], p+x*size/2.0, q+y*size/2.0, r+z*size/2.0, size/2.0);
        if(this->entries[i] != NULL)
            this->entries[i]->bufferize(buffer, this->p*size+x*size/2.0, this->q*size+y*size/2.0, this->r*size+z*size/2.0, size/2.0);
    }
}

void Octree::bufferizeEntry(GlobalBuffer* buffer, unsigned char type, float p, float q, float r, float* ao, float width)
{
    float size = 1.0/subSize;
    
    int x = 0;
    int y = 0;
    int z = 0;
    
    /*ao[0] = 0;
     ao[1] = 0;
     ao[2] = 0;
     ao[3] = 0;
     
     
     ao[0] = 0.5;
     ao[1] = 0.5;
     ao[2] = 0;
     ao[3] = 0;
     Cube::bufferizeSquare(scene, x+p,      y+q, z+r, x+p,      y+q+size, z+r+size, color, ao); //side
     Cube::bufferizeSquare(scene, x+p+size, y+q, z+r, x+p+size, y+q+size, z+r+size, color, ao);*/
    
    //TemplateDebug::debug();
    
    /*p = (this->psize/subSize)) + (this->size/subSize)*p/(size);
    q = (this->q*(this->size/this->subSize)) + (this->size/this->subSize)*q/(this->size);
    r = (this->r*(this->size/this->subSize)) + (this->size/this->subSize)*r/(this->size);*/
    
    /*p = (p-this->p)/(subSize) + this->p;
    q = (q-this->q)/(subSize) + this->q;
    r = (r-this->r)/(subSize) + this->r;*/
    
    ao[0] = 0.5;
    ao[1] = 0.5;
    ao[2] = 0.5;
    ao[3] = 0.5;
    
    //ao[0] = -0.5;
    //ao[1] = -0.5;
    
    //Cube::bufferizePoint(scene, p, q, r, type, 1.0);
    
    buffer->getData()->push_back(p);
    buffer->getData()->push_back(q);
    buffer->getData()->push_back(r);

    buffer->getData()->push_back(type);
    
    buffer->getData()->push_back(width);
    
    return;
}

void Octree::bufferize(VBOScene* scene, OctreeEntry* octreeEntry, float p, float q, float r, int size)
{
    /*Leaf* leaf = dynamic_cast<Leaf*>(octreeEntry);
    if(leaf != NULL)
    {
        if(leaf->getLeaf() > 0)
        {
                    int abs_x = p;
                    while (abs_x<0)
                        abs_x += this->size; //temp
                    abs_x = abs_x % this->size;
            
                    int abs_y = q;
                        while (abs_y<0)
                            abs_y += this->size; //temp
                    abs_y = abs_y % this->size;
        
                    int abs_z = r;
                    while (abs_z<0)
                        abs_z += this->size; //temp
                    abs_z = abs_z % this->size;

                if(isCubeVisible(abs_x, abs_y, abs_z))
                {
                    glm::vec3 color = CubeType::getColor(leaf->getLeaf(), q);
                    
                    int x = 0;
                    int y = 0;
                    int z = 0;
            
                    float* ao = new float[4];
                    
                    ao[0] = 0.5;
                    ao[1] = 0.5;
                    ao[2] = 0.5;
                    ao[3] = 0.5;
                
                    bufferizeEntry(scene, leaf->getLeaf(), p, q, r, ao);
                
                    ao[0] = 0;
                    ao[1] = 0;
                    ao[2] = 0;
                    ao[3] = 0;
                 }
            }
        }

        Node* node = dynamic_cast<Node*>(octreeEntry);
        if(node != NULL)
        {
            if(node->getEntries().size() > 0)
                for(int i = 0; i < 8; i++)
                {
                    int x = (i%4)%2;
                    int y = i/4;
                    int z = (i%4)/2;
            
                    bufferize(scene, node->getEntries()[i], p+x*size/2, q+y*size/2, r+z*size/2, size / 2);
                }
        }*/
    
}

bool Octree::isCubeVisible(int x, int y, int z, int size)
{
    //OctreeEntry* test = this->getAbs(x, y,   z, size);
    
    if( x==0 || z==0 || x==(size-1) || y==(size-1) || z==(size-1) )
        return true;
    
    if( y==0 && x>0 && z>0 && x<(size-1) && z<(size-1) )
        return false;
    
    //try
    {
        //TemplateDebug::debug();
        bool test =    !(this->getAbs(x-1, y,   z, size) != 0 //temp
                      && this->getAbs(x+1, y,   z, size) != 0
                      && this->getAbs(x,   y-1, z, size) != 0
                      && this->getAbs(x,   y+1, z, size) != 0
                      && this->getAbs(x,   y,   z-1, size) != 0
                      && this->getAbs(x,   y,   z+1, size) != 0);
        return test;
    }
    /*catch(out_of_range e)
    {
        return true;
    }*/
    return true;
}

