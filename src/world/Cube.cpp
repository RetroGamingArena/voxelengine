//
//  Cube.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 29/12/2014.
//  Copyright (c) 2014 RGA. All rights reserved.
//

#include "Cube.h"

void Cube::bufferize(VBOScene* scene)
{
    int cursor = scene->getVertexbuffer()->getCursor();

    //bufferizeSquare(scene, -1.0, -1.0, -1.0, 1.0, 1.0, -1.0);
    
    bufferizeSquare(scene, -1.0, -1.0, 1.0, 1.0, 1.0, 1.0);
    
    /*scene->getVertexbuffer()->getData()[cursor++] = -1.0f;
    scene->getVertexbuffer()->getData()[cursor++] = -1.0f;
    scene->getVertexbuffer()->getData()[cursor++] = 0.0f;
    scene->getVertexbuffer()->getData()[cursor++] = 1.0f;
    scene->getVertexbuffer()->getData()[cursor++] = -1.0f;
    scene->getVertexbuffer()->getData()[cursor++] = 0.0f;
    scene->getVertexbuffer()->getData()[cursor++] = 0.0f;
    scene->getVertexbuffer()->getData()[cursor++] = 1.0f;
    scene->getVertexbuffer()->getData()[cursor++] = 0.0f;*/
    
    scene->getVertexbuffer()->setCursor(cursor);
}

void Cube::bufferizeSquare(VBOScene* scene, int x1, int y1, int z1, int x2, int y2, int z2)
{
    int cursor = scene->getVertexbuffer()->getCursor();
    
    if(z1==z2)
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
    
    /*scene->getVertexbuffer()->getData()[cursor++] = x1;
    scene->getVertexbuffer()->getData()[cursor++] = y1;
    scene->getVertexbuffer()->getData()[cursor++] = z2;
    
    scene->getVertexbuffer()->getData()[cursor++] = x1;
    scene->getVertexbuffer()->getData()[cursor++] = y2;
    scene->getVertexbuffer()->getData()[cursor++] = z2;
    
    scene->getVertexbuffer()->getData()[cursor++] = x2;
    scene->getVertexbuffer()->getData()[cursor++] = y2;
    scene->getVertexbuffer()->getData()[cursor++] = z2;*/
    
    scene->getVertexbuffer()->setCursor(cursor);
}