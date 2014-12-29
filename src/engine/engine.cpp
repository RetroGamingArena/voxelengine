//
//  engine.cpp
//  voxelengine
//
//  Created by Julien CAILLABET on 27/12/2014.
//  Copyright (c) 2014 Julien CAILLABET. All rights reserved.
//

#include <cstdlib>

#include "engine.h"
#include "../scene/VoxelScene.h"

Engine* Engine::instance = NULL;

Engine::Engine()
{
    windowWidth = 640;
    windowHeight = 480;
    if (!glfwInit())
        exit(EXIT_FAILURE);
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWmonitor *monitor = NULL;
    window = glfwCreateWindow(windowWidth, windowHeight, "Voxel Engine", monitor, NULL);
    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
        exit(EXIT_FAILURE);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    scene = new VoxelScene(window);
}

Engine* Engine::getInstance()
{
    if(instance == NULL)
        instance = new Engine();
    return instance;
}

int Engine::run()
{
    //window open
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    while (!glfwWindowShouldClose(window))
    {
        scene->render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    
    glfwTerminate();
    exit(EXIT_SUCCESS);
    
    return 0;
}