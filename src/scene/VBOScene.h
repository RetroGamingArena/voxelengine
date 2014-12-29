//
//  VBOScene.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 28/12/2014.
//  Copyright (c) 2014 RGA. All rights reserved.
//

#ifndef __Voxelengine__VBOScene__
#define __Voxelengine__VBOScene__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

#include "Scene.h"
#include "../openGL/ShaderLoader.h"
#include "../openGL/Buffer.h"

class VBOScene : public Scene
{
    protected:
        GLuint VertexArrayID;
        GLuint programID;
        GLuint vertexbufferID;
        Buffer* vertexBuffer;
        GLfloat* colorBuffer;

    public:
        VBOScene(GLFWwindow* window) : Scene(window)
        {
            glGenVertexArrays(1, &VertexArrayID);
            glBindVertexArray(VertexArrayID);
            
            glGenBuffers(1, &vertexbufferID);
            glBindBuffer(GL_ARRAY_BUFFER, vertexbufferID);
            
            programID = ShaderLoader::load( "shaders/vertexShader.glsl", "shaders/fragmentShader.glsl" );
            
            matrixID = glGetUniformLocation(programID, "MVP");
        }
        Buffer* getVertexbuffer(){return vertexBuffer;}
        void bindBuffer();
        void render();
        void init();
        virtual int getVertexCount() = 0;
};

#endif /* defined(__Voxelengine__VBOScene__) */
