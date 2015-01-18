//
//  GPUProcessor.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 15/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include "GPUProcessor.h"

void GPUProcessor::bufferize(VBOScene* scene, World* world)
{
    glm:: vec3 test = scene->getCamera()->unproject(512, 384);
    
    glm::vec3 v2 = scene->getCamera()->unproject(0, 0);
    glm::vec3 v1 = scene->getCamera()->unproject(1024.0, 0);
    glm::vec3 v4 = scene->getCamera()->unproject(0, 768.0);
    glm::vec3 v3 = scene->getCamera()->unproject(1024.0, 768.0);
    
    //scene->getCamera()->
    
    for(int i=0; i < world->getChunks().size(); i++)
    {
        Chunk* chunk = world->getChunks()[i];
        Cube::bufferizeCube(scene, 1, chunk->getP(), chunk->getQ(), chunk->getR(), Chunk::size);
    }
    /*glm::vec3 v2 = scene->getCamera()->unproject(0, 0);
    glm::vec3 v1 = scene->getCamera()->unproject(1024.0, 0);
    glm::vec3 v4 = scene->getCamera()->unproject(0, 768.0);
    glm::vec3 v3 = scene->getCamera()->unproject(1024.0, 768.0);
    
    (*scene->getBuffer()->getData()).push_back(v1.x);
    (*scene->getBuffer()->getData()).push_back(v1.y);
    (*scene->getBuffer()->getData()).push_back(v1.z);
    (*scene->getBuffer()->getData()).push_back(1);
    (*scene->getBuffer()->getData()).push_back(0.5);
    
    (*scene->getBuffer()->getData()).push_back(v2.x);
    (*scene->getBuffer()->getData()).push_back(v2.y);
    (*scene->getBuffer()->getData()).push_back(v2.z);
    (*scene->getBuffer()->getData()).push_back(1.0);
    (*scene->getBuffer()->getData()).push_back(0.5);
    
    (*scene->getBuffer()->getData()).push_back(v3.x);
    (*scene->getBuffer()->getData()).push_back(v3.y);
    (*scene->getBuffer()->getData()).push_back(v3.z);
    (*scene->getBuffer()->getData()).push_back(1.0);
    (*scene->getBuffer()->getData()).push_back(0.5);
    
    (*scene->getBuffer()->getData()).push_back(v4.x);
    (*scene->getBuffer()->getData()).push_back(v4.y);
    (*scene->getBuffer()->getData()).push_back(v4.z);
    (*scene->getBuffer()->getData()).push_back(1.0);
    (*scene->getBuffer()->getData()).push_back(0.5);
    
    scene->getIndices()->getData()->push_back(0);
    scene->getIndices()->getData()->push_back(1);
    scene->getIndices()->getData()->push_back(2);
    scene->getIndices()->getData()->push_back(1);
    scene->getIndices()->getData()->push_back(2);
    scene->getIndices()->getData()->push_back(3);*/
}