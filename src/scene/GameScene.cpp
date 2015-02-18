//
//  GameScene.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 16/02/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include "GameScene.h"

#include "../engine/engine.h"

void GameScene::onMouseMotion(double xpos, double ypos)
{
    VoxelScene::onMouseMotion(xpos, ypos);
    
    double angleY = Engine::getInstance()->getPlayer()->getAngleY();
    double angleZ = Engine::getInstance()->getPlayer()->getAngleZ();
    
    angleY += dX;
    angleY = fmod(angleY, 360);
    
    angleZ += dY;
    angleZ = fmod(angleZ, 360);
    
    Engine::getInstance()->getPlayer()->setAngleY(angleY);
    //Engine::getInstance()->getPlayer()->setAngleZ(angleZ);
}