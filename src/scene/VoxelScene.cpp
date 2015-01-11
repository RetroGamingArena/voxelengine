//
//  VoxelScene.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 28/12/2014.
//  Copyright (c) 2014 RGA. All rights reserved.
//

#include <iostream>

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
    
    glm::vec3 mouse3D = camera->unproject(xpos, ypos);
    
    glm::vec3 position = camera->getPosition();
    
    float dx = (mouse3D.x - position.x) * 1000;
    float dy = (mouse3D.y - position.y) * 1000;
    float dz = (mouse3D.z - position.z) * 1000;
    
    for(int i = 0; i < 500; i++)
    {
        float xx = dx * i + mouse3D.x;
        float yy = dy * i + mouse3D.y;
        float zz = dz * i + mouse3D.z;
        
        OctreeEntry<unsigned char>* octreeEntry = world->getPointedCube(xx, yy, zz);
        if(octreeEntry == NULL)
            continue;
        octreeEntry = world->getPointedCube(xx, yy, zz);
        unsigned char type = octreeEntry->getLeaf();
        if(type > 0)
        {
            octreeEntry->setLeaf(0);
            
            buffer->getData()->clear();
            indices->getData()->clear();
            
            world->bufferize(this);
            
            glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*buffer->getData()->size(), &(*buffer->getData())[0], GL_STATIC_DRAW);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices->getData()->size() * sizeof(unsigned int), &(*indices->getData())[0] , GL_STATIC_DRAW);
            
            std::cout << "OK" << endl;
            break;
        }
    }
    
    //glm::vec3 mouse3D = world->getPointedCube(xpos, ypos);
    
    //std::cout << mouse3D.x << " " << mouse3D.y << " " << mouse3D.z << endl;
}