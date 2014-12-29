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
    return 3;
}

void VoxelScene::init()
{
    VBOScene::init();
    
    world->bufferize(this);
    
    bindBuffer();
}