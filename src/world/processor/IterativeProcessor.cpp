//
//  IterativeProcessor.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 15/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include "IterativeProcessor.h"

void IterativeProcessor::bufferize(VBOScene* scene, World* world)
{
    int x = 0;
    int y = 0;
    int z = 0;
    
    int p = 1;
    int q = 0;
    int r = 1;
    
    float size = 1.0 / Chunk::subsize;
    
    float type = 2;
    
    float* ao = new float[4];
    
    ao[0] = 0.5;
    ao[1] = 0.5;
    ao[2] = 0.5;
    ao[3] = 0.5;
    
    Cube::bufferizeSquare(scene, x+p, y+q,      z+r, x+p+size, y+q,      z+r+size, type, ao); //bottom
    
    Cube::bufferizeIndice(scene, 0);
    Cube::bufferizeIndice(scene, 1);
    Cube::bufferizeIndice(scene, 2);
    Cube::bufferizeIndice(scene, 1);
    Cube::bufferizeIndice(scene, 2);
    Cube::bufferizeIndice(scene, 3);
    
    ao[0] = 0;
    ao[1] = 0;
    ao[2] = 0;
    ao[3] = 0;
    
    Cube::bufferizeSquare(scene, x+p, y+q+size, z+r, x+p+size, y+q+size, z+r+size, type, ao); //top
    
    Cube::bufferizeIndice(scene, 4);
    Cube::bufferizeIndice(scene, 5);
    Cube::bufferizeIndice(scene, 6);
    Cube::bufferizeIndice(scene, 5);
    Cube::bufferizeIndice(scene, 6);
    Cube::bufferizeIndice(scene, 7);
    
    Cube::bufferizeIndice(scene, 0);
    Cube::bufferizeIndice(scene, 1);
    Cube::bufferizeIndice(scene, 4);
    Cube::bufferizeIndice(scene, 1);
    Cube::bufferizeIndice(scene, 4);
    Cube::bufferizeIndice(scene, 5);
    
    Cube::bufferizeIndice(scene, 1);
    Cube::bufferizeIndice(scene, 3);
    Cube::bufferizeIndice(scene, 5);
    Cube::bufferizeIndice(scene, 3);
    Cube::bufferizeIndice(scene, 5);
    Cube::bufferizeIndice(scene, 7);
    
    Cube::bufferizeIndice(scene, 3);
    Cube::bufferizeIndice(scene, 2);
    Cube::bufferizeIndice(scene, 7);
    Cube::bufferizeIndice(scene, 2);
    Cube::bufferizeIndice(scene, 7);
    Cube::bufferizeIndice(scene, 6);
    
    Cube::bufferizeIndice(scene, 2);
    Cube::bufferizeIndice(scene, 0);
    Cube::bufferizeIndice(scene, 6);
    Cube::bufferizeIndice(scene, 0);
    Cube::bufferizeIndice(scene, 6);
    Cube::bufferizeIndice(scene, 4);
    
    for(int i=0; i < world->getChunks().size() ; i++)
    {
        if( world->getChunks()[i]->getOctree()->getEntries() != NULL )
            world->getChunks()[i]->bufferize(scene);
    }
}