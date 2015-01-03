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

void Cube::bufferize(VBOScene* scene, float x, float y, float z)
{
    bufferizeSquare(scene, this->x+x,      this->y+y, this->z+z, this->x+x,      this->y+y+size, this->z+z+size);
    bufferizeSquare(scene, this->x+x+size, this->y+y, this->z+z, this->x+x+size, this->y+y+size, this->z+z+size);
    
    bufferizeSquare(scene, this->x+x, this->y+y,      this->z+z, this->x+x+size, this->y+y,      this->z+z+size);
    bufferizeSquare(scene, this->x+x, this->y+y+size, this->z+z, this->x+x+size, this->y+y+size, this->z+z+size);
    
    bufferizeSquare(scene, this->x+x, this->y+y, this->z+z,      this->x+x+size, this->y+y+size, this->z+z);
    bufferizeSquare(scene, this->x+x, this->y+y, this->z+z+size, this->x+x+size, this->y+y+size, this->z+z+size);
    
    glm::vec3 color = CubeType::getColor(this);
    
    for(int i = 0; i<6; i++)
        for(int j = 0; j<6; j++)
            bufferizeSquareColor(scene, color.r, color.g,  color.b);
}

void Cube::bufferizeSquareColor(VBOScene* scene, float r, float g, float b)
{
    //int cursor = scene->getColorBuffer()->getCursor();
    
    //std::vector<GLfloat>* data  = scene->getColorBuffer()->getData();
    //data->resize(data->size()+4);
    
    (*scene->getColorBuffer()->getData()).push_back(r);
    (*scene->getColorBuffer()->getData()).push_back(g);
    (*scene->getColorBuffer()->getData()).push_back(b);
    (*scene->getColorBuffer()->getData()).push_back(0.5);
    
    //scene->getColorBuffer()->setCursor(cursor);
}

void Cube::bufferizeSquare(VBOScene* scene, float x1, float y1, float z1, float x2, float y2, float z2)
{
    //int cursor = scene->getVertexbuffer()->getCursor();
    
    //std::vector<GLfloat>* data  = scene->getVertexbuffer()->getData();
    //data->resize(data->size()+12);

    if(x1==x2)
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
    }
    
    //scene->getVertexbuffer()->setCursor(cursor);
}