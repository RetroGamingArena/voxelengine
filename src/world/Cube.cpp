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
    scene->getVertexbuffer()->getData()[0] = -1.0f;
    scene->getVertexbuffer()->getData()[1] = -1.0f;
    scene->getVertexbuffer()->getData()[2] = 0.0f;
    scene->getVertexbuffer()->getData()[3] = 1.0f;
    scene->getVertexbuffer()->getData()[4] = -1.0f;
    scene->getVertexbuffer()->getData()[5] = 0.0f;
    scene->getVertexbuffer()->getData()[6] = 0.0f;
    scene->getVertexbuffer()->getData()[7] = 1.0f;
    scene->getVertexbuffer()->getData()[8] = 0.0f;
}