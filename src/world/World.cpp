//
//  World.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 28/12/2014.
//  Copyright (c) 2014 RGA. All rights reserved.
//

#include "World.h"
#include "Octree.h"

int World::size=2;

void World::bufferize(VBOScene* scene)
{
    /*float* ao = new float[4];
    
    glm::vec3 position = scene->getCamera()->getPosition();
    
    for(int x = 0; x < 1024; x=x+2)
        for(int y = 0; y < 768; y=y+2)
        {
            
            glm::vec3 mouse3D = scene->getCamera()->unproject(x, y);
            
            float dx = (mouse3D.x - position.x) * 1000;
            float dy = (mouse3D.y - position.y) * 1000;
            float dz = (mouse3D.z - position.z) * 1000;
            
            for(int i = 0; i < 57; i++)
            {
                float xx = dx * i + mouse3D.x;
                float yy = dy * i + mouse3D.y;
                float zz = dz * i + mouse3D.z;
                
                OctreeEntry<unsigned char>* octreeEntry = getPointedCube(xx, yy, zz);
                if( octreeEntry == NULL)
                    continue;
                unsigned char type = octreeEntry->getLeaf();
                if(type > 0 && !octreeEntry->isDrawn())
                {
                    Octree<unsigned char>::bufferizeEntry(scene, type, (int)xx, (int)yy, (int)zz, ao);
                    octreeEntry->setDrawn(true);
                    break;
                }
            }
        }*/
    
    for(int i=0; i < chunks.size() ; i++)
    {
        chunks[i]->bufferize(scene);
    }
}

int World::cubeCount()
{
    int res = 0;
    for(int i=0; i < chunks.size() ; i++)
    {
        //res += chunks[i]->getCubes().size();
    }
    return res;
}

OctreeEntry<unsigned char>* World::getPointedCube(int x, int y, int z)
{
    for(int i=0; i < chunks.size() ; i++)
    {
        if( chunks[i]->contains(x, y, z) )
        {
            return chunks[i]->getOctree()->getAbs(x,y,z, Chunk::size);
        }
    }
    return 0;
}