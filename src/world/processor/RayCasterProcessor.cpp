//
//  RayCasterProcessor.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 15/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include "../../engine/engine.h"
#include "RayCasterProcessor.h"
#include "../../collision/Ray.h"

void RayCasterProcessor::bufferize(VBOScene* scene, World* world)
{
    float* ao = new float[4];
    
    glm::vec3 position = scene->getCamera()->getPosition();
    
    for(int i=0; i < (World::size*2+1)*(World::size*2+1) ; i++)
        world->getChunks()[i]->getOctree()->invalidate();
    
    glm::vec3 v2 = scene->getCamera()->unproject(0, 0);
    glm::vec3 v1 = scene->getCamera()->unproject(1024.0, 0);
    glm::vec3 v4 = scene->getCamera()->unproject(0, 768.0);
    glm::vec3 v3 = scene->getCamera()->unproject(1024.0, 768.0);
    
    for(int x = 0; x < 1024; x=x+1)
    {
        glm::vec3 vx1 = (v1-v2);
        vx1 *= x;
        vx1 /= 1024.0;
        vx1 = vx1 + v2;
        
        glm::vec3 vx2 = (v3-v4);
        vx2 *= x;
        vx2 /= 1024.0;
        vx2 = vx2 + v4;
        
        for(int y = 0; y < 768; y=y+1)
        {
            glm::vec3 vxy = (vx2-vx1);
            vxy *= y;
            vxy /= Engine::getInstance()->getWindowHeight();

            glm::vec3 mouse3D = vx1+vxy;
            Ray* ray = new Ray(position, mouse3D);
            
            int i = 0;
            
            while(i < 160 )
            {
                glm::vec3 d = ray->move(i);
                
                OctreeEntry<unsigned char>* octreeEntry = world->getPointedCube(d.x, d.y, d.z);
                if( octreeEntry == NULL)
                {
                    i++;
                    continue;
                }
                if( octreeEntry->isDrawn() )
                    break;
                unsigned char type = octreeEntry->getLeaf();
                if(type > 0)
                {
                    //Octree<unsigned char>::bufferizeEntry(scene, type, (int)d.x, (int)d.y, (int)d.z, ao);
                    //octreeEntry->setDrawn(true);
                    break;
                }

                i++;
            }
        }
    }
}