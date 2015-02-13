//
//  Cube.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 29/12/2014.
//  Copyright (c) 2014 RGA. All rights reserved.
//

#include "Cube.h"
#include "Chunk.h"
#include "CubeType.h"

float Cube::size = 1.0;

void Cube::bufferizeVertex(VBOScene* scene, float x, float y, float z, float type, float ao)
{
    (*scene->getBuffer()->getData()).push_back(x);
    (*scene->getBuffer()->getData()).push_back(y);
    (*scene->getBuffer()->getData()).push_back(z);
    (*scene->getBuffer()->getData()).push_back(ao);
    (*scene->getBuffer()->getData()).push_back(1);
    (*scene->getBuffer()->getData()).push_back(1);
}

void Cube::bufferizeIndice(VBOScene* scene, unsigned short indice)
{
    int size = scene->getIndices()->getData()->size()/36;
    scene->getIndices()->getData()->push_back(size*8+indice);
}

void Cube::bufferizeSquare(VBOScene* scene, float x1, float y1, float z1, float x2, float y2, float z2, float type, float* ao)
{
    if(x1==x2)
    {
        bufferizeVertex(scene, x1, y1, z1, type, ao[0]);
        bufferizeVertex(scene, x1, y1, z2, type, ao[1]);
        bufferizeVertex(scene, x1, y2, z1, type, ao[2]);
        bufferizeVertex(scene, x1, y2, z2, type, ao[3]);
    }
    else if(y1==y2)
    {
        bufferizeVertex(scene, x1, y1, z1, type, ao[0]);
        bufferizeVertex(scene, x1, y1, z2, type, ao[1]);
        bufferizeVertex(scene, x2, y1, z1, type, ao[2]);
        bufferizeVertex(scene, x2, y1, z2, type, ao[3]);
    }
    else if(z1==z2)
    {
        bufferizeVertex(scene, x1, y1, z1, type, ao[0]);
        bufferizeVertex(scene, x1, y2, z1, type, ao[1]);
        bufferizeVertex(scene, x2, y1, z1, type, ao[2]);
        bufferizeVertex(scene, x2, y2, z1, type, ao[3]);
    }
}