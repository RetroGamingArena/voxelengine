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
#include "Camera.h"
#include "World.h"

#include "../world/processor/WorldProcessor.h"

class Engine
{
    int windowWidth;
    int windowHeight;
    GLFWwindow* window;
    
    Scene* scene;
    World* world;
    
    static Engine *instance;
    WorldProcessor* processor;

    int nbFrames;
    double lastTime;
    double FPS;
    
    Engine();

    static void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
    static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    static void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);
    
    public:
        WorldProcessor* getProcessor(){return processor;}
        static Engine* getInstance();
        GLFWwindow* getWindow(){return window;}
        Scene* getScene(){return scene;}
        World* getWorld(){return world;}
        void setWorld(World* world){this->world=world;}
        void setScene(Scene* scene){this->scene=scene;}
        int run();
};

#endif /* defined(__voxelengine__engine__) */
