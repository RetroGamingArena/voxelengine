//
//  RayCasterProcessor.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 15/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include "RayCasterProcessor.h"

void RayCasterProcessor::bufferize(VBOScene* scene, World* world)
{
    float* ao = new float[4];
    
    glm::vec3 position = scene->getCamera()->getPosition();
    
    for(int i=0; i < (World::size*2+1)*(World::size*2+1) ; i++)
        world->getChunks()[i]->getOctree()->invalidate();
    
    for(int x = 0; x < 1024; x=x+1)
        for(int y = 0; y < 768; y=y+1)
        {
            glm::vec3 mouse3D = scene->getCamera()->unproject(x, y);
            
            float dx = (mouse3D.x - position.x) * 1000;
            float dy = (mouse3D.y - position.y) * 1000;
            float dz = (mouse3D.z - position.z) * 1000;
            
            for(int i = 0; i < 120; i=i+1)
            {
                float xx = dx * i + mouse3D.x;
                float yy = dy * i + mouse3D.y;
                float zz = dz * i + mouse3D.z;
                
                OctreeEntry<unsigned char>* octreeEntry = world->getPointedCube(xx, yy, zz);
                if( octreeEntry == NULL)
                    continue;
                if( octreeEntry->isDrawn() )
                    break;
                unsigned char type = octreeEntry->getLeaf();
                if(type > 0)
                {
                    Octree<unsigned char>::bufferizeEntry(scene, type, (int)xx, (int)yy, (int)zz, ao);
                    octreeEntry->setDrawn(true);
                    break;
                }
            }
        }
}