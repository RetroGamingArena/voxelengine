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
        VoxelScene* voxenScene = new VoxelScene(Engine::getInstance()->getWindow());
        voxenScene->init();
        Engine::getInstance()->setScene(voxenScene);
        mutex->unlock();
    }
}

void LoadingScene::initWorld()
{
    Engine::getInstance()->setWorld(new World());
    /*VoxelScene* voxenScene = new VoxelScene(Engine::getInstance()->getWindow());
    voxenScene->init();
    Engine::getInstance()->setScene(voxenScene);*/
    mutex->unlock();
}