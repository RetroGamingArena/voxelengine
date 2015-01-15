//
//  VoxelScene.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 28/12/2014.
//  Copyright (c) 2014 RGA. All rights reserved.
//

#include <iostream>

#include "VoxelScene.h"
#include "../engine/engine.h"

std::mutex* VoxelScene::mutex = new std::mutex();

void VoxelScene::init()
{
    VBOScene::init();
    
    Engine::getInstance()->getProcessor()->bufferize(this, Engine::getInstance()->getWorld());
    //Engine::getInstance()->getWorld()->bufferize(this);
    
    bindBuffer();
}

void VoxelScene::onMouseMotion(double xpos, double ypos)
{
    World* world =  Engine::getInstance()->getWorld();
    
    Scene::onMouseMotion(xpos, ypos);
    
    glm::vec3 mouse3D = camera->unproject(xpos, 768-ypos);
    
    glm::vec3 position = camera->getPosition();
    
    float dx = (mouse3D.x - position.x) * 1000;
    float dy = (mouse3D.y - position.y) * 1000;
    float dz = (mouse3D.z - position.z) * 1000;
    
    /*if(thread == NULL)
    {
        buffer->getData()->clear();
        indices->getData()->clear();
        thread = new std::thread(bufferize, this);
        mutex->lock();
    }
    
    if( thread != NULL && mutex->try_lock() )
    {
        glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*buffer->getData()->size(), &(*buffer->getData())[0], GL_STATIC_DRAW);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices->getData()->size() * sizeof(unsigned int), &(*indices->getData())[0] , GL_STATIC_DRAW);
        mutex->unlock();
        thread = NULL;
    }*/
    
    for(int i = 0; i < 80; i++)
    {
        float xx = dx * i + mouse3D.x;
        float yy = dy * i + mouse3D.y;
        float zz = dz * i + mouse3D.z;
        
        OctreeEntry<unsigned char>* octreeEntry = world->getPointedCube(xx, yy, zz);
        if(octreeEntry == NULL)
            continue;
        unsigned char type = octreeEntry->getLeaf();
        if(type > 0)
        {
            //OctreeEntry<unsigned char>* test = world->getChunks()[0]->getOctree()->getAbs((int)xx, (int)yy, (int)zz, 32);
            
            //world->getChunks()[0]->getOctree()->setCube((int)xx,(int)yy,(int)zz,32,2);
            
            //octreeEntry->setLeaf(1);
            
            /*buffer->getData()->clear();
            indices->getData()->clear();
            
            world->bufferize(this);
            
            glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*buffer->getData()->size(), &(*buffer->getData())[0], GL_STATIC_DRAW);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices->getData()->size() * sizeof(unsigned int), &(*indices->getData())[0] , GL_STATIC_DRAW);
            
            std::cout << (int)xx << " " << (int)yy << " " << (int)zz << endl;
            break;*/
        }
    }
    
    //glm::vec3 mouse3D = world->getPointedCube(xpos, ypos);
    
    //std::cout << mouse3D.x << " " << mouse3D.y << " " << mouse3D.z << endl;
}

void VoxelScene::bufferize(VoxelScene* voxelScene)
{
    Engine::getInstance()->getProcessor()->bufferize(voxelScene, Engine::getInstance()->getWorld());
    //Engine::getInstance()->getWorld()->bufferize(voxelScene);
    mutex->unlock();
}

void VoxelScene::render()
{
    VBOScene::render();
    glClearColor(0.5f, 0.9f, 1.0f, 0.0f);
}