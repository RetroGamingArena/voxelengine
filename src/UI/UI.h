//
//  UI.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 05/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#ifndef __Voxelengine__UI__
#define __Voxelengine__UI__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <vector>

#include "../../depends/glm/glm.hpp"
#include "../../depends/glm/gtc/matrix_transform.hpp"

#include "../openGL/ShaderLoader.h"
#include "../openGL/Buffer.h"
#include "../openGL/GlobalBuffer.h"
#include "control/Control.h"
#include "control/Label.h"

#include "../../depends/lodepng/lodepng.h"

class Control;

class UI
{
    GLuint matrixID;
    
    glm::mat4 projection;
    glm::mat4 view;
    glm::mat4 model;
    glm::mat4 MVP;
    
    GLuint vertexArrayID;
    GLuint programID;
    
    GLuint bufferID;
    GlobalBuffer* buffer;
    
    GLuint fontID;
    
    GLuint fontVertexBufferID;
    GLuint fontUVBufferID;
    
    GLuint textUniformID;
    
    void load_png_texture(const char *file_name);
    void flip_image_vertical(unsigned char *data, unsigned int width, unsigned int height);
    
    protected:
        std::vector<Control*> controls;
    
    public:
        virtual void render();
        UI()
        {
            buffer = new GlobalBuffer();
            
            view = glm::mat4(1.0f);
            projection = glm::ortho(0, 1024, 768, 0);
            model = glm::mat4(1.0f);
            MVP = projection * view * model;
            
            //TextureUtils::loadTexture("textures/font.png", GL_TEXTURE1, GL_LINEAR, false);
            //void TextureUtils::loadTexture(const char* texturePath, GLenum activeTexture, int minMagFilter, bool clampToEdge)
            //{
            textUniformID = glGetUniformLocation( programID, "myTextureSampler" );
            
            glGenTextures(1, &fontID);
            glActiveTexture(GL_TEXTURE1);
            glBindTexture(GL_TEXTURE_2D, fontID);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            load_png_texture("textures/font.png");
            
            glGenVertexArrays(1, &vertexArrayID);
            glBindVertexArray(vertexArrayID);
            
            glGenBuffers(1, &fontVertexBufferID);
            glGenBuffers(1, &fontUVBufferID);
            
            programID = ShaderLoader::load( "shaders/uiVertexShader.glsl", "shaders/uiFragmentShader.glsl" );
            
            buffer->getData()->push_back(10);
            buffer->getData()->push_back(10);
            
            buffer->getData()->push_back(10);
            buffer->getData()->push_back(20);
            
            buffer->getData()->push_back(20);
            buffer->getData()->push_back(10);
            
            buffer->getData()->push_back(10);
            buffer->getData()->push_back(20);
            
            buffer->getData()->push_back(20);
            buffer->getData()->push_back(10);
            
            buffer->getData()->push_back(20);
            buffer->getData()->push_back(20);
            
            glGenBuffers(1, &bufferID);
            glBindBuffer(GL_ARRAY_BUFFER, bufferID);
            glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*buffer->getData()->size(), &(*buffer->getData())[0], GL_STATIC_DRAW);
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }
        std::vector<Control*> getControls(){return controls;};
        void printText(const char * text, int x, int y, int size);
};

#endif /* defined(__Voxelengine__UI__) */
