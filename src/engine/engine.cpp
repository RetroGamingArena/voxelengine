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
#include "../camera/TrackBallCamera.h"

Engine* Engine::instance = NULL;

Engine::Engine()
{
    nbFrames = 0;
    windowWidth = 1024;
    windowHeight = 768;
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
    //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetCursorPosCallback(window, cursorPositionCallback);
    glfwSetScrollCallback(window, scrollCallback);
    
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
        exit(EXIT_FAILURE);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    glClearColor(0.5f, 0.9f, 1.0f, 0.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    //camera = new TrackBallCamera();
    scene = new VoxelScene(window);
    scene->init();
}

Engine* Engine::getInstance()
{
    if(instance == NULL)
        instance = new Engine();
    return instance;
}

void Engine::cursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
{
    Engine* engine = getInstance();
    engine->getScene()->onMouseMotion(xpos, ypos);
}

void Engine::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    Engine* engine = getInstance();
    engine->getScene()->getCamera()->onMouseButton(button, action);
}
void Engine::scrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
    Engine* engine = getInstance();
    engine->getScene()->getCamera()->onMouseWheel(xoffset, yoffset);
}

int Engine::run()
{
    //window open
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    while (glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(window) == 0 )
    {
        scene->getCamera()->look();
        scene->render();
        
        //FPS
        nbFrames++;
        double currentTime = glfwGetTime();
        if ( currentTime - lastTime >= (1.0 / 60) )
        {
            FPS = nbFrames;
            Label* label = (Label*)scene->getUI()->getControls()[0];
            char caption [25];
            sprintf (caption, "Minequest - FPS:  %i t", nbFrames);
            label->setCaption(caption);
            nbFrames = 0;
            lastTime += 1.0;
        }
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    
    glfwTerminate();
    exit(EXIT_SUCCESS);
    
    return 0;
}