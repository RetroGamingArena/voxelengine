//
//  LoadingScene.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 12/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include "LoadingScene.h"
#include "VoxelScene.h"
#include "engine.h"

std::mutex* LoadingScene::mutex = new std::mutex();

void LoadingScene::render()
{
    VBOScene::render();
    if(thread == NULL)
    {
        thread = new std::thread (initWorld);
        mutex->lock();
        //thread->join();
        //Engine::getInstance()->setScene(new VoxelScene(Engine::getInstance()->getWindow()));
    }
    if(mutex->try_lock())
    {
        VoxelScene* voxelScene = new VoxelScene(Engine::getInstance()->getWindow());
        voxelScene->init();
        Engine::getInstance()->getProcessor()->bufferize(voxelScene, Engine::getInstance()->getWorld());
        voxelScene->bindBuffer();
        Engine::getInstance()->setScene(voxelScene);
        mutex->unlock();
    }
}

void LoadingScene::initWorld()
{
    Engine::getInstance()->setWorld(new World());
    while(Engine::getInstance()->getWorld()->hasNext() && Engine::getInstance()->getWorld()->isRunning())
    {
        
    }
    /*VoxelScene* voxenScene = new VoxelScene(Engine::getInstance()->getWindow());
    voxenScene->init();
    Engine::getInstance()->setScene(voxenScene);*/
    mutex->unlock();
}