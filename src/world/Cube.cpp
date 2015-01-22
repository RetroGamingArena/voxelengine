//
//  Cube.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 29/12/2014.
//  Copyright (c) 2014 RGA. All rights reserved.
//

#include "Cube.h"
#include "Chunk.h"
#include "CubeType.h"

float Cube::size = 1.0;

int Cube::getIndex(int x, int y, int z)
{
    return x+z*Chunk::size+y*Chunk::size*Chunk::size;
}

glm::vec3 Cube::getCoords(int index)
{
    int SIZE_SIZE = Chunk::size*Chunk::size;
    
    glm::vec3 res;
    res.x = (index % (SIZE_SIZE)) % Chunk::size;
    res.y = (index / (SIZE_SIZE));
    res.z = (index % (SIZE_SIZE)) / Chunk::size;
    return res;
}

void Cube::bufferize(VBOScene* scene, float x, float y, float z)
{
    glm::vec3 color = CubeType::getColor(this);
    
    bufferizeSquare(scene, this->x+x,      this->y+y, this->z+z, this->x+x,      this->y+y+size, this->z+z+size, color, NULL);
    bufferizeSquare(scene, this->x+x+size, this->y+y, this->z+z, this->x+x+size, this->y+y+size, this->z+z+size, color, NULL);
    
    bufferizeSquare(scene, this->x+x, this->y+y,      this->z+z, this->x+x+size, this->y+y,      this->z+z+size, color, NULL);
    bufferizeSquare(scene, this->x+x, this->y+y+size, this->z+z, this->x+x+size, this->y+y+size, this->z+z+size, color, NULL);
    
    bufferizeSquare(scene, this->x+x, this->y+y, this->z+z,      this->x+x+size, this->y+y+size, this->z+z,      color, NULL);
    bufferizeSquare(scene, this->x+x, this->y+y, this->z+z+size, this->x+x+size, this->y+y+size, this->z+z+size, color, NULL);

    /*for(int i = 0; i<6; i++)
        for(int j = 0; j<6; j++)
            bufferizeSquareColor(scene, color.r, color.g,  color.b);*/
}

void Cube::bufferizeVertex(VBOScene* scene, float x, float y, float z, float r, float g, float b, float ao)
{
    /*r = 1.0;
    g = 1.0;
    b = 1.0;*/
    
    (*scene->getBuffer()->getData()).push_back(x);
    (*scene->getBuffer()->getData()).push_back(y);
    (*scene->getBuffer()->getData()).push_back(z);
    (*scene->getBuffer()->getData()).push_back(r);
    (*scene->getBuffer()->getData()).push_back(g);
    (*scene->getBuffer()->getData()).push_back(b);

    (*scene->getBuffer()->getData()).push_back(ao);
}

void Cube::bufferizeVertex(VBOScene* scene, float x, float y, float z, float type, float ao)
{
    /*r = 1.0;
     g = 1.0;
     b = 1.0;*/
    
    (*scene->getBuffer()->getData()).push_back(x);
    (*scene->getBuffer()->getData()).push_back(y);
    (*scene->getBuffer()->getData()).push_back(z);
    (*scene->getBuffer()->getData()).push_back(type);
    //(*scene->getBuffer()->getData()).push_back(g);
    //(*scene->getBuffer()->getData()).push_back(b);
    
    (*scene->getBuffer()->getData()).push_back(ao);
}

void Cube::bufferizeSquareColor(VBOScene* scene, float r, float g, float b)
{
    /*(*scene->getColorBuffer()->getData()).push_back(r);
    (*scene->getColorBuffer()->getData()).push_back(g);
    (*scene->getColorBuffer()->getData()).push_back(b);
    (*scene->getColorBuffer()->getData()).push_back(0.5);*/
}

void Cube::bufferizeIndice(VBOScene* scene, unsigned short indice)
{
    int size = scene->getIndices()->getData()->size()/36;
    scene->getIndices()->getData()->push_back(size*8+indice);
}

void Cube::bufferizeSquare(VBOScene* scene, float x1, float y1, float z1, float x2, float y2, float z2, glm::vec3 color, float* ao)
{
    int a = 2;
}

void Cube::bufferizeSquare(VBOScene* scene, float x1, float y1, float z1, float x2, float y2, float z2, float type, float* ao)
{
    if(x1==x2)
    {
        bufferizeVertex(scene, x1, y1, z1, type, ao[0]);
        //bufferizeIndice(scene, 0);
        bufferizeVertex(scene, x1, y1, z2, type, ao[1]);
        //bufferizeIndice(scene, 1);
        bufferizeVertex(scene, x1, y2, z1, type, ao[2]);
        //bufferizeIndice(scene, 2);
        //bufferizeIndice(scene, 2);
        //bufferizeIndice(scene, 1);
        bufferizeVertex(scene, x1, y2, z2, type, ao[3]);
        //bufferizeIndice(scene, 3);
    }
    else if(y1==y2)
    {
        bufferizeVertex(scene, x1, y1, z1, type, ao[0]);
        //bufferizeIndice(scene, 0);
        bufferizeVertex(scene, x1, y1, z2, type, ao[1]);
        //bufferizeIndice(scene, 1);
        bufferizeVertex(scene, x2, y1, z1, type, ao[2]);
        //bufferizeIndice(scene, 2);
        //bufferizeIndice(scene, 2);
        //bufferizeIndice(scene, 1);
        bufferizeVertex(scene, x2, y1, z2, type, ao[3]);
        //bufferizeIndice(scene, 3);
    }
    else if(z1==z2)
    {
        bufferizeVertex(scene, x1, y1, z1, type, ao[0]);
        //bufferizeIndice(scene, 0);
        bufferizeVertex(scene, x1, y2, z1, type, ao[1]);
        //bufferizeIndice(scene, 1);
        bufferizeVertex(scene, x2, y1, z1, type, ao[2]);
        //bufferizeIndice(scene, 2);
        //bufferizeIndice(scene, 2);
        //bufferizeIndice(scene, 1);
        bufferizeVertex(scene, x2, y2, z1, type, ao[3]);
        //bufferizeIndice(scene, 3);
    }
}

void Cube::bufferizePoint(VBOScene* scene, float x, float y, float z, float type, float ao)
{
    bufferizeVertex(scene, x, y, z, type, ao);
}

void Cube::bufferizeSquare(VBOScene* scene, float x1, float y1, float z1, float x2, float y2, float z2)
{

}

void Cube::bufferizeCube(VBOScene* scene, unsigned char type, float p, float q, float r, int size)
{
    float* ao = new float[4];
    int x = 0;
    int y = 0;
    int z = 0;
    
    ao[0] = 0.5;
    ao[1] = 0.5;
    ao[2] = 0.5;
    ao[3] = 0.5;
    
    Cube::bufferizeSquare(scene, x+p, y+q,      z+r, x+p+size, y+q,      z+r+size, type, ao); //bottom
    
    Cube::bufferizeIndice(scene, 0);
    Cube::bufferizeIndice(scene, 1);
    Cube::bufferizeIndice(scene, 2);
    Cube::bufferizeIndice(scene, 1);
    Cube::bufferizeIndice(scene, 2);
    Cube::bufferizeIndice(scene, 3);
    
    ao[0] = 0;
    ao[1] = 0;
    ao[2] = 0;
    ao[3] = 0;
    
    Cube::bufferizeSquare(scene, x+p, y+q+size, z+r, x+p+size, y+q+size, z+r+size, type, ao); //top
    
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
}