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

template<typename T>
void Octree<T>::bufferize(VBOScene* scene, float p, float q, float r) //TODO octree offset
{
        for(int i = 0; i < 8; i++)
        {
            int x = (i%4)%2;
            int y = i/4;
            int z = (i%4)/2;

            bufferize(scene, this->entries[i], p+x*size/2.0, q+y*size/2.0, r+z*size/2.0, size);
        }
}

template<typename T>
void Octree<T>::bufferize(VBOScene* scene, OctreeEntry<T>* octreeEntry, float p, float q, float r, int size)
{
    if(octreeEntry->getEntries() == NULL)
    {
        if(octreeEntry->getLeaf() > 0)
        {
            int abs_x = p;
            while (abs_x<0)
                abs_x += 32; //temp
            abs_x = abs_x % 32;
            
            int abs_y = q;
            while (abs_y<0)
                abs_y += 32; //temp
            abs_y = abs_y % 32;
        
            int abs_z = r;
            while (abs_z<0)
                abs_z += 32; //temp
            abs_z = abs_z % 32;

            if(isCubeVisible(abs_x, abs_y, abs_z))
            {
                glm::vec3 color = CubeType::getColor(octreeEntry->getLeaf(), q);
        
                int x = 0;
                int y = 0;
                int z = 0;
            
                float* ao = new float[4];
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
        
                ao[0] = 0.5;
                ao[1] = 0.5;
                ao[2] = 0.5;
                ao[3] = 0.5;
                
                //ao[0] = -0.5;
                //ao[1] = -0.5;
                Cube::bufferizeSquare(scene, x+p, y+q,      z+r, x+p+size, y+q,      z+r+size, octreeEntry->getLeaf(), ao); //bottom
                
                Cube::bufferizeIndice(scene, 0);
                Cube::bufferizeIndice(scene, 1);
                Cube::bufferizeIndice(scene, 2);
                Cube::bufferizeIndice(scene, 1);
                Cube::bufferizeIndice(scene, 2);
                Cube::bufferizeIndice(scene, 3);
                
                if( this->getAbs(abs_x-1, abs_y+1,   abs_z, 32) != 0 && this->getAbs(abs_x, abs_y+1,   abs_z-1, 32) != 0 )
                {
                  //   ao[0] = 0.5; //first
                  //  ao[3] = -0.5; //first
                }
                if( this->getAbs(abs_x-1, abs_y+1,   abs_z, 32) != 0 && this->getAbs(abs_x, abs_y+1,   abs_z+1, 32) != 0 )
                {
                    //ao[0] = 0.5;
                    //ao[1] = 1; //right
                    //ao[2] = 0;
                    //ao[3] = 0.5;
                }
                if( this->getAbs(abs_x+1, abs_y+1,   abs_z, 32) != 0 && this->getAbs(abs_x, abs_y+1,   abs_z-1, 32) != 0 )
                {
                   //  ao[2] = 0.5;
                   // ao[1] = -0.5; //left
                }
                if( this->getAbs(abs_x+1, abs_y+1,   abs_z, 32) != 0 && this->getAbs(abs_x, abs_y+1,   abs_z+1, 32) != 0 )
                {
                   //  ao[0] = -0.5; //first
                  //  ao[3] = 0.5; //last
                }
                
                ao[0] = 0;
                ao[1] = 0;
                ao[2] = 0;
                ao[3] = 0;
                
                Cube::bufferizeSquare(scene, x+p, y+q+size, z+r, x+p+size, y+q+size, z+r+size, octreeEntry->getLeaf(), ao); //top

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
                
                /*ao[0] = 0.5;
                ao[1] = 0;
                ao[2] = 0.5;
                ao[3] = 0;
                Cube::bufferizeSquare(scene, x+p, y+q, z+r,      x+p+size, y+q+size, z+r,      color, ao);
                Cube::bufferizeSquare(scene, x+p, y+q, z+r+size, x+p+size, y+q+size, z+r+size, color, ao);*/ //side
            }
        }
    }
    else
    {
        for(int i = 0; i < 8; i++)
        {
            int x = (i%4)%2;
            int y = i/4;
            int z = (i%4)/2;
            
            bufferize(scene, octreeEntry->getEntries()[i], p+x*size/4, q+y*size/4, r+z*size/4, size / 2);
        }
    }
}

template<typename T>
bool Octree<T>::isCubeVisible(int x, int y, int z)
{
    if( x==0 || y==0 || z==0 || x==(size-1) || y==(size-1) || z==(size-1) )
        return true;
    
    //try
    {
        bool test =    !(this->getAbs(x-1, y,   z, 32) != 0 //temp
                      && this->getAbs(x+1, y,   z, 32) != 0
                      && this->getAbs(x,   y-1, z, 32) != 0
                      && this->getAbs(x,   y+1, z, 32) != 0
                      && this->getAbs(x,   y,   z-1, 32) != 0
                      && this->getAbs(x,   y,   z+1, 32) != 0);
        return test;
    }
    /*catch(out_of_range e)
    {
        return true;
    }*/
    return true;
}