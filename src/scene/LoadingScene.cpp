//
//  LoadingScene.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 12/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include "LoadingScene.h"
#include "GameScene.h"
#include "engine.h"

std::mutex* LoadingScene::mutex = new std::mutex();

void LoadingScene::render()
{
    VBOScene::render();
    if(thread == NULL)
    {
        thread = new std::thread (initWorld);
        mutex->lock();
    }
    if(mutex->try_lock())
    {
        GameScene* gameScene = new GameScene(Engine::getInstance()->getWindow(), Engine::getInstance()->getPlayer());
        gameScene->init();
        
        Engine::getInstance()->getProcessor()->bufferize(gameScene, Engine::getInstance()->getWorld());
        
        gameScene->bindBuffer();
        Engine::getInstance()->setScene(gameScene);
        Engine::getInstance()->getPlayer()->setFalling(true);
        mutex->unlock();
    }
}

void LoadingScene::initWorld()
{
    Engine::getInstance()->setWorld(new World());
    mutex->unlock();
}