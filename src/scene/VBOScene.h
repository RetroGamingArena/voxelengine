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
#include <vector>

#include "Scene.h"
#include "../openGL/ShaderLoader.h"
#include "../openGL/GlobalBuffer.h"
#include "../openGL/IndiceBuffer.h"

using namespace std;

class VBOScene : public Scene
{
    protected:
        GLuint VertexArrayID;
    
    
        vector<GLuint> bufferIDs;
        GLuint elementbuffer;
        vector<GlobalBuffer*> buffers;
        IndiceBuffer* indices;

    public:
        static GLuint programID;
        VBOScene(GLFWwindow* window) : Scene(window)
        {
            //glGenVertexArrays(1, &VertexArrayID);
            //glBindVertexArray(VertexArrayID);
        }
        GlobalBuffer* getBuffer(){return buffers[0];}
        IndiceBuffer* getIndices(){return indices;}
        void bindBuffer();
        void render();
        void init();
        //virtual int getVertexCount() = 0;
};

#endif /* defined(__Voxelengine__VBOScene__) */
