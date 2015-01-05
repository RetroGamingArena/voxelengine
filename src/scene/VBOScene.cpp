//
//  VBOScene.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 28/12/2014.
//  Copyright (c) 2014 RGA. All rights reserved.
//

#include "VBOScene.h"
#include "../openGL/VertexBuffer.h"
#include "../openGL/ColorBuffer.h"
#include "../openGL/GlobalBuffer.h"

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
    
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (void*)0 );
    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (void*)(sizeof(GLfloat) * 3));
    
    glDrawArrays(GL_TRIANGLES, 0, buffer->getData()->size());
    
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
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
}

void VBOScene::init()
{
    this->buffer = new GlobalBuffer();
}