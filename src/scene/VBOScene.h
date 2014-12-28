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

class VBOScene : public Scene
{
    GLuint VertexArrayID;

    public:
        VBOScene(GLFWwindow* window) : Scene(window)
        {
            //glGenVertexArrays(1, &VertexArrayID);
            //glBindVertexArray(VertexArrayID);
        }
        void render();
};

#endif /* defined(__Voxelengine__VBOScene__) */
