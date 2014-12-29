//
//  Scene.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 28/12/2014.
//  Copyright (c) 2014 RGA. All rights reserved.
//

#ifndef __Voxelengine__Scene__
#define __Voxelengine__Scene__

#include <stdio.h>
#include <glew.h>
#include <GLFW/glfw3.h>

class Scene
{
    protected:
        GLFWwindow* window;
    
    public:
        Scene(GLFWwindow* window){this->window = window;}
        virtual void render() = 0;
        virtual void init() = 0;
};

#endif /* defined(__Voxelengine__Scene__) */
