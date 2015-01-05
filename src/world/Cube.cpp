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
    
    bufferizeSquare(scene, this->x+x,      this->y+y, this->z+z, this->x+x,      this->y+y+size, this->z+z+size, color);
    bufferizeSquare(scene, this->x+x+size, this->y+y, this->z+z, this->x+x+size, this->y+y+size, this->z+z+size, color);
    
    bufferizeSquare(scene, this->x+x, this->y+y,      this->z+z, this->x+x+size, this->y+y,      this->z+z+size, color);
    bufferizeSquare(scene, this->x+x, this->y+y+size, this->z+z, this->x+x+size, this->y+y+size, this->z+z+size, color);
    
    bufferizeSquare(scene, this->x+x, this->y+y, this->z+z,      this->x+x+size, this->y+y+size, this->z+z,      color);
    bufferizeSquare(scene, this->x+x, this->y+y, this->z+z+size, this->x+x+size, this->y+y+size, this->z+z+size, color);

    /*for(int i = 0; i<6; i++)
        for(int j = 0; j<6; j++)
            bufferizeSquareColor(scene, color.r, color.g,  color.b);*/
}

void Cube::bufferizeVertex(VBOScene* scene, float x, float y, float z, float r, float g, float b)
{
    (*scene->getBuffer()->getData()).push_back(x);
    (*scene->getBuffer()->getData()).push_back(y);
    (*scene->getBuffer()->getData()).push_back(z);
    (*scene->getBuffer()->getData()).push_back(r);
    (*scene->getBuffer()->getData()).push_back(g);
    (*scene->getBuffer()->getData()).push_back(b);
}

void Cube::bufferizeSquareColor(VBOScene* scene, float r, float g, float b)
{
    /*(*scene->getColorBuffer()->getData()).push_back(r);
    (*scene->getColorBuffer()->getData()).push_back(g);
    (*scene->getColorBuffer()->getData()).push_back(b);
    (*scene->getColorBuffer()->getData()).push_back(0.5);*/
}

void Cube::bufferizeSquare(VBOScene* scene, float x1, float y1, float z1, float x2, float y2, float z2, glm::vec3 color)
{
    if(x1==x2)
    {
        bufferizeVertex(scene, x1, y1, z1, color.r, color.g, color.b);
        bufferizeVertex(scene, x1, y1, z2, color.r, color.g, color.b);
        bufferizeVertex(scene, x1, y2, z1, color.r, color.g, color.b);
        bufferizeVertex(scene, x1, y1, z2, color.r, color.g, color.b);
        bufferizeVertex(scene, x1, y2, z1, color.r, color.g, color.b);
        bufferizeVertex(scene, x1, y2, z2, color.r, color.g, color.b);
    }
    else if(y1==y2)
    {
        bufferizeVertex(scene, x1, y1, z1, color.r, color.g, color.b);
        bufferizeVertex(scene, x1, y1, z2, color.r, color.g, color.b);
        bufferizeVertex(scene, x2, y1, z1, color.r, color.g, color.b);
        bufferizeVertex(scene, x1, y1, z2, color.r, color.g, color.b);
        bufferizeVertex(scene, x2, y1, z1, color.r, color.g, color.b);
        bufferizeVertex(scene, x2, y1, z2, color.r, color.g, color.b);
    }
    else if(z1==z2)
    {
        bufferizeVertex(scene, x1, y1, z1, color.r, color.g, color.b);
        bufferizeVertex(scene, x1, y2, z1, color.r, color.g, color.b);
        bufferizeVertex(scene, x2, y1, z1, color.r, color.g, color.b);
        bufferizeVertex(scene, x1, y2, z1, color.r, color.g, color.b);
        bufferizeVertex(scene, x2, y1, z1, color.r, color.g, color.b);
        bufferizeVertex(scene, x2, y2, z1, color.r, color.g, color.b);
    }
}

void Cube::bufferizeSquare(VBOScene* scene, float x1, float y1, float z1, float x2, float y2, float z2)
{
    /*if(x1==x2)
    {
        
        (*scene->getVertexbuffer()->getData()).push_back(x1);
        (*scene->getVertexbuffer()->getData()).push_back(y1);
        (*scene->getVertexbuffer()->getData()).push_back(z1);
    
        (*scene->getVertexbuffer()->getData()).push_back(x1);
        (*scene->getVertexbuffer()->getData()).push_back(y1);
        (*scene->getVertexbuffer()->getData()).push_back(z2);
    
        (*scene->getVertexbuffer()->getData()).push_back(x1);
        (*scene->getVertexbuffer()->getData()).push_back(y2);
        (*scene->getVertexbuffer()->getData()).push_back(z1);
        
        (*scene->getVertexbuffer()->getData()).push_back(x1);
        (*scene->getVertexbuffer()->getData()).push_back(y1);
        (*scene->getVertexbuffer()->getData()).push_back(z2);
        
        (*scene->getVertexbuffer()->getData()).push_back(x1);
        (*scene->getVertexbuffer()->getData()).push_back(y2);
        (*scene->getVertexbuffer()->getData()).push_back(z1);
        
        (*scene->getVertexbuffer()->getData()).push_back(x1);
        (*scene->getVertexbuffer()->getData()).push_back(y2);
        (*scene->getVertexbuffer()->getData()).push_back(z2);
    }
    else if(y1==y2)
    {
        (*scene->getVertexbuffer()->getData()).push_back(x1);
        (*scene->getVertexbuffer()->getData()).push_back(y1);
        (*scene->getVertexbuffer()->getData()).push_back(z1);
        
        (*scene->getVertexbuffer()->getData()).push_back(x1);
        (*scene->getVertexbuffer()->getData()).push_back(y1);
        (*scene->getVertexbuffer()->getData()).push_back(z2);
        
        (*scene->getVertexbuffer()->getData()).push_back(x2);
        (*scene->getVertexbuffer()->getData()).push_back(y1);
        (*scene->getVertexbuffer()->getData()).push_back(z1);
        
        (*scene->getVertexbuffer()->getData()).push_back(x1);
        (*scene->getVertexbuffer()->getData()).push_back(y1);
        (*scene->getVertexbuffer()->getData()).push_back(z2);
       
        (*scene->getVertexbuffer()->getData()).push_back(x2);
        (*scene->getVertexbuffer()->getData()).push_back(y1);
        (*scene->getVertexbuffer()->getData()).push_back(z1);
        
        (*scene->getVertexbuffer()->getData()).push_back(x2);
        (*scene->getVertexbuffer()->getData()).push_back(y1);
        (*scene->getVertexbuffer()->getData()).push_back(z2);
    }
    else if(z1==z2)
    {
        (*scene->getVertexbuffer()->getData()).push_back(x1);
        (*scene->getVertexbuffer()->getData()).push_back(y1);
        (*scene->getVertexbuffer()->getData()).push_back(z1);
        
        (*scene->getVertexbuffer()->getData()).push_back(x1);
        (*scene->getVertexbuffer()->getData()).push_back(y2);
        (*scene->getVertexbuffer()->getData()).push_back(z1);
        
        (*scene->getVertexbuffer()->getData()).push_back(x2);
        (*scene->getVertexbuffer()->getData()).push_back(y1);
        (*scene->getVertexbuffer()->getData()).push_back(z1);
        
        (*scene->getVertexbuffer()->getData()).push_back(x1);
        (*scene->getVertexbuffer()->getData()).push_back(y2);
        (*scene->getVertexbuffer()->getData()).push_back(z1);
        
        (*scene->getVertexbuffer()->getData()).push_back(x2);
        (*scene->getVertexbuffer()->getData()).push_back(y1);
        (*scene->getVertexbuffer()->getData()).push_back(z1);
        
        (*scene->getVertexbuffer()->getData()).push_back(x2);
        (*scene->getVertexbuffer()->getData()).push_back(y2);
        (*scene->getVertexbuffer()->getData()).push_back(z1);
    }*/
}