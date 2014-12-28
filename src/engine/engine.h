//
//  engine.h
//  voxelengine
//
//  Created by Julien CAILLABET on 27/12/2014.
//  Copyright (c) 2014 Julien CAILLABET. All rights reserved.
//

#ifndef __voxelengine__engine__
#define __voxelengine__engine__

#include <stdio.h>
#include <glew.h>
#include <GLFW/glfw3.h>

#include "Scene.h"

class Engine
{
    int windowWidth;
    int windowHeight;
    GLFWwindow* window;
    
    Scene* scene;
    
    static Engine *instance;
    Engine();

    public:
        static Engine* getInstance();
        int run();
};

#endif /* defined(__voxelengine__engine__) */
