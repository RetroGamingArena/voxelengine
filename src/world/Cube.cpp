//
//  Cube.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 29/12/2014.
//  Copyright (c) 2014 RGA. All rights reserved.
//

#include "Cube.h"
#include "Chunk.h"

float Cube::size = 1.0;

void Cube::bufferize(VBOScene* scene, float x, float y, float z)
{
    bufferizeSquare(scene, this->x+x,      this->y+y, this->z+z, this->x+x,      this->y+y+size, this->z+z+size);
    bufferizeSquare(scene, this->x+x+size, this->y+y, this->z+z, this->x+x+size, this->y+y+size, this->z+z+size);
    
    bufferizeSquare(scene, this->x+x, this->y+y,      this->z+z, this->x+x+size, this->y+y,      this->z+z+size);
    bufferizeSquare(scene, this->x+x, this->y+y+size, this->z+z, this->x+x+size, this->y+y+size, this->z+z+size);
    
    bufferizeSquare(scene, this->x+x, this->y+y, this->z+z,      this->x+x+size, this->y+y+size, this->z+z);
    bufferizeSquare(scene, this->x+x, this->y+y, this->z+z+size, this->x+x+size, this->y+y+size, this->z+z+size);
    
    for(int i = 0; i<6; i++)
    {
        float color = this->y/(float)Chunk::size;
        for(int j = 0; j<6; j++)
        bufferizeSquareColor(scene, 0, color,  0);
    }
}

void Cube::bufferizeSquareColor(VBOScene* scene, float r, float g, float b)
{
    int cursor = scene->getColorBuffer()->getCursor();
    
    scene->getColorBuffer()->getData()[cursor++] = r;
    scene->getColorBuffer()->getData()[cursor++] = g;
    scene->getColorBuffer()->getData()[cursor++] = b;
    scene->getColorBuffer()->getData()[cursor++] = 0.5;
    
    scene->getColorBuffer()->setCursor(cursor);
}

void Cube::bufferizeSquare(VBOScene* scene, float x1, float y1, float z1, float x2, float y2, float z2)
{
    int cursor = scene->getVertexbuffer()->getCursor();
    
    if(x1==x2)
    {
        scene->getVertexbuffer()->getData()[cursor++] = x1;
        scene->getVertexbuffer()->getData()[cursor++] = y1;
        scene->getVertexbuffer()->getData()[cursor++] = z1;
    
        scene->getVertexbuffer()->getData()[cursor++] = x1;
        scene->getVertexbuffer()->getData()[cursor++] = y1;
        scene->getVertexbuffer()->getData()[cursor++] = z2;
    
        scene->getVertexbuffer()->getData()[cursor++] = x1;
        scene->getVertexbuffer()->getData()[cursor++] = y2;
        scene->getVertexbuffer()->getData()[cursor++] = z1;
        
        scene->getVertexbuffer()->getData()[cursor++] = x1;
        scene->getVertexbuffer()->getData()[cursor++] = y1;
        scene->getVertexbuffer()->getData()[cursor++] = z2;
        
        scene->getVertexbuffer()->getData()[cursor++] = x1;
        scene->getVertexbuffer()->getData()[cursor++] = y2;
        scene->getVertexbuffer()->getData()[cursor++] = z1;
        
        scene->getVertexbuffer()->getData()[cursor++] = x1;
        scene->getVertexbuffer()->getData()[cursor++] = y2;
        scene->getVertexbuffer()->getData()[cursor++] = z2;
    }
    else if(y1==y2)
    {
        scene->getVertexbuffer()->getData()[cursor++] = x1;
        scene->getVertexbuffer()->getData()[cursor++] = y1;
        scene->getVertexbuffer()->getData()[cursor++] = z1;
        
        scene->getVertexbuffer()->getData()[cursor++] = x1;
        scene->getVertexbuffer()->getData()[cursor++] = y1;
        scene->getVertexbuffer()->getData()[cursor++] = z2;
        
        scene->getVertexbuffer()->getData()[cursor++] = x2;
        scene->getVertexbuffer()->getData()[cursor++] = y1;
        scene->getVertexbuffer()->getData()[cursor++] = z1;
        
        scene->getVertexbuffer()->getData()[cursor++] = x1;
        scene->getVertexbuffer()->getData()[cursor++] = y1;
        scene->getVertexbuffer()->getData()[cursor++] = z2;
        
        scene->getVertexbuffer()->getData()[cursor++] = x2;
        scene->getVertexbuffer()->getData()[cursor++] = y1;
        scene->getVertexbuffer()->getData()[cursor++] = z1;
        
        scene->getVertexbuffer()->getData()[cursor++] = x2;
        scene->getVertexbuffer()->getData()[cursor++] = y1;
        scene->getVertexbuffer()->getData()[cursor++] = z2;
    }
    else if(z1==z2)
    {
        scene->getVertexbuffer()->getData()[cursor++] = x1;
        scene->getVertexbuffer()->getData()[cursor++] = y1;
        scene->getVertexbuffer()->getData()[cursor++] = z1;
        
        scene->getVertexbuffer()->getData()[cursor++] = x1;
        scene->getVertexbuffer()->getData()[cursor++] = y2;
        scene->getVertexbuffer()->getData()[cursor++] = z1;
        
        scene->getVertexbuffer()->getData()[cursor++] = x2;
        scene->getVertexbuffer()->getData()[cursor++] = y1;
        scene->getVertexbuffer()->getData()[cursor++] = z1;
        
        scene->getVertexbuffer()->getData()[cursor++] = x1;
        scene->getVertexbuffer()->getData()[cursor++] = y2;
        scene->getVertexbuffer()->getData()[cursor++] = z1;
        
        scene->getVertexbuffer()->getData()[cursor++] = x2;
        scene->getVertexbuffer()->getData()[cursor++] = y1;
        scene->getVertexbuffer()->getData()[cursor++] = z1;
        
        scene->getVertexbuffer()->getData()[cursor++] = x2;
        scene->getVertexbuffer()->getData()[cursor++] = y2;
        scene->getVertexbuffer()->getData()[cursor++] = z1;
    }
    
    scene->getVertexbuffer()->setCursor(cursor);
}