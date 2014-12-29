//
//  VBOScene.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 28/12/2014.
//  Copyright (c) 2014 RGA. All rights reserved.
//

#include "VBOScene.h"

void VBOScene::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(programID);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
                          0,                  // attribut 0. Aucune raison particulière pour 0, mais cela doit correspondre au « layout » dans le shader
                          3,                  // taille
                          GL_FLOAT,           // type
                          GL_FALSE,           // normalisé ?
                          0,                  // nombre d'octets séparant deux sommets dans le tampon
                          (void*)0            // décalage du tableau de tampon
                          );
    
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    glDisableVertexAttribArray(0);
}

void VBOScene::bindBuffer()
{
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*9, buffer, GL_STATIC_DRAW);
}