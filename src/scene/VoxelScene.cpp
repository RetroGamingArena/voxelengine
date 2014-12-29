//
//  VoxelScene.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 28/12/2014.
//  Copyright (c) 2014 RGA. All rights reserved.
//

#include "VoxelScene.h"

int VoxelScene::getVertexCount()
{
    return 9;
}

void VoxelScene::init()
{
    VBOScene::init();
    vertexBuffer[0] = -1.0f;
    vertexBuffer[1] = -1.0f;
    vertexBuffer[2] = 0.0f;
    vertexBuffer[3] =  1.0f;
    vertexBuffer[4] = -1.0f;
    vertexBuffer[5] = 0.0f;
    vertexBuffer[6] = 0.0f;
    vertexBuffer[7] = 1.0f;
    vertexBuffer[8] = 0.0f;
    bindBuffer();
}