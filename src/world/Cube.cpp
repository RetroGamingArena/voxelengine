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

    scene->getVertexbuffer()->getData()[cursor++] = -1.0f;
    scene->getVertexbuffer()->getData()[cursor++] = -1.0f;
    scene->getVertexbuffer()->getData()[cursor++] = 0.0f;
    scene->getVertexbuffer()->getData()[cursor++] = 1.0f;
    scene->getVertexbuffer()->getData()[cursor++] = -1.0f;
    scene->getVertexbuffer()->getData()[cursor++] = 0.0f;
    scene->getVertexbuffer()->getData()[cursor++] = 0.0f;
    scene->getVertexbuffer()->getData()[cursor++] = 1.0f;
    scene->getVertexbuffer()->getData()[cursor++] = 0.0f;
    
    scene->getVertexbuffer()->setCursor(cursor);
}