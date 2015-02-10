//
//  VoxelScene.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 28/12/2014.
//  Copyright (c) 2014 RGA. All rights reserved.
//

#ifndef __Voxelengine__VoxelScene__
#define __Voxelengine__VoxelScene__

#include <stdio.h>
#include <thread>
#include <mutex>

#include "VBOScene.h"

class VoxelScene : public VBOScene
{
    std::thread* thread;
    static std::mutex* mutex;
    
    GLuint textureID;
    GLuint textUniformID;

    public:
        VoxelScene(GLFWwindow* window) : VBOScene(window)
        {
            ui = new DebugUI();
            thread = NULL;
            
            textUniformID = glGetUniformLocation( programID, "myTextureSampler" );
            
            glGenTextures(1, &textureID);
            glActiveTexture(GL_TEXTURE1);
            glBindTexture(GL_TEXTURE_2D, textureID);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        
            unsigned char * data = new unsigned char[16*16];
            for(int i = 0; i < 16*16; i++ )
                data[i] = i/10.0;
            glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, 16, 16, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, data);
        }
        void init();
        void onMouseScroll(double xoffset, double yoffset);
        void onMouseMotion(double xpos, double ypos);
        void render();
        static void bufferize(VoxelScene* voxelScene);
};

#endif /* defined(__Voxelengine__VoxelScene__) */
