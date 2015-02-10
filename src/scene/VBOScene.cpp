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

GLuint VBOScene::programID = 0;

void VBOScene::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(programID);

    // Enable blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    //3D
    glUniformMatrix4fv(matrixID, 1, GL_FALSE, &getCamera()->getMVP()[0][0]);
    
    glUniformMatrix4fv(mMatrixID, 1, GL_FALSE, &getCamera()->getModel()[0][0]);
    glUniformMatrix4fv(vMatrixID, 1, GL_FALSE, &getCamera()->getView()[0][0]);
    glUniformMatrix4fv(pMatrixID, 1, GL_FALSE, &getCamera()->getProjection()[0][0]);
    glUniformMatrix4fv(cameraUnprojectionID, 1, GL_FALSE, &getCamera()->getUnprojection()[0][0]);
    glUniform3fv(cameraPositionVecID, 1, &getCamera()->getPosition()[0]);
    
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
    
    glBindBuffer(GL_ARRAY_BUFFER, bufferID);
    
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glEnableVertexAttribArray(3);
    glEnableVertexAttribArray(4);
    glEnableVertexAttribArray(5);
    //glEnableVertexAttribArray(6);

    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (void*)0 );
    glVertexAttribPointer( 1, 1, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (void*)(sizeof(GLfloat) * 3));
    //glVertexAttribPointer( 2, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 8, (void*)4 );
    //glVertexAttribPointer( 1, 1, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (void*)(sizeof(GLfloat) * 4));
    
    glVertexAttribPointer( 2, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (void*)0 ); //0, NULL);
    glVertexAttribDivisor( 2, 1);
    glVertexAttribPointer( 3, 1, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (void*)(sizeof(GLfloat) * 3)); //0, NULL);
    glVertexAttribDivisor( 3, 1);
    glVertexAttribPointer( 4, 1, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (void*)(sizeof(GLfloat) * 4)); //0, NULL);
    glVertexAttribDivisor( 4, 1);
    glVertexAttribPointer( 5, 1, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (void*)(sizeof(GLfloat) * 5)); //0, NULL);
    glVertexAttribDivisor( 5, 1);

    //glDrawArrays(GL_POINTS, 0, buffer->getData()->size());
    int size = indices->getData()->size();
    //glDrawElements(GL_TRIANGLES, size, GL_UNSIGNED_INT, (void*)0);           // element array buffer offset
    glDrawElementsInstanced(GL_TRIANGLE_STRIP, 32, GL_UNSIGNED_INT, (void*)0, (buffer->getData()->size()-32)/6 );           // element array buffer offset
    
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
    glDisableVertexAttribArray(3);
    glDisableVertexAttribArray(4);
    glDisableVertexAttribArray(5);
    //glDisableVertexAttribArray(6);
    
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