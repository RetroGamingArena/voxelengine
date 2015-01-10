//
//  VBOScene.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 28/12/2014.
//  Copyright (c) 2014 RGA. All rights reserved.
//

#include "VBOScene.h"
#include "../openGL/GlobalBuffer.h"
#include "../openGL/IndiceBuffer.h"

void VBOScene::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(programID);

    //3D
    glUniformMatrix4fv(matrixID, 1, GL_FALSE, &getCamera()->getMVP()[0][0]);
    
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
    
    glBindBuffer(GL_ARRAY_BUFFER, bufferID);
    
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 7, (void*)0 );
    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 7, (void*)(sizeof(GLfloat) * 3));
    glVertexAttribPointer( 2, 1, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 7, (void*)(sizeof(GLfloat) * 6));
    
    //glDrawArrays(GL_TRIANGLES, 0, buffer->getData()->size());
    glDrawElements(GL_TRIANGLES, indices->getData()->size(), GL_UNSIGNED_INT, (void*)0);           // element array buffer offset
    
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    //2D
    ui->render();
}

void VBOScene::bindBuffer()
{
    glGenBuffers(1, &bufferID);
    glBindBuffer(GL_ARRAY_BUFFER, bufferID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*buffer->getData()->size(), &(*buffer->getData())[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    glGenBuffers(1, &elementbuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices->getData()->size() * sizeof(unsigned int), &(*indices->getData())[0] , GL_STATIC_DRAW);
}

void VBOScene::init()
{
    this->buffer = new GlobalBuffer();
    this->indices = new IndiceBuffer();
}