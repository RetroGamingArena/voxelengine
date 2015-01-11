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
    return world->cubeCount()*6*6;
}

void VoxelScene::init()
{
    VBOScene::init();
    
    world->bufferize(this);
    
    bindBuffer();
}

void VoxelScene::onMouseMotion(double xpos, double ypos)
{
    Scene::onMouseMotion(xpos, ypos);
}