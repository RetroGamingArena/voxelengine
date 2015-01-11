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
    
    glm::vec3 pos = glm::vec3(xpos, ypos, 0.0f);
    glm::vec4 viewportdata = glm::vec4(0.0f, 0.0f, 1024.0f, 768.0f);
    
    glm::vec3 position = camera->getPosition();
    glm::vec3 mouse3D = glm::unProject(pos, camera->getView()*camera->getModel(), camera->getProjection(), viewportdata);
    
    float dx = (mouse3D.x - position.x) * 1000;
    float dy = (mouse3D.y - position.y) * 1000;
    float dz = (mouse3D.z - position.z) * 1000;
    
    for(int i = 0; i < 500; i++)
    {
        float xx = dx * i + mouse3D.x;
        float yy = dy * i + mouse3D.y;
        float zz = dz * i + mouse3D.z;
        
        unsigned char type = world->getPointedCube(xx, yy, zz);
        if(type > 0)
        {
            std::cout << "OK" << endl;
        }
    }
    
    //glm::vec3 mouse3D = world->getPointedCube(xpos, ypos);
    
    //std::cout << mouse3D.x << " " << mouse3D.y << " " << mouse3D.z << endl;
}