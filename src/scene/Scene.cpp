//
//  Scene.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 28/12/2014.
//  Copyright (c) 2014 RGA. All rights reserved.
//

#include "Scene.h"

GLuint Scene::matrixID = 0;

GLuint Scene::mMatrixID = 0;
GLuint Scene::vMatrixID = 0;
GLuint Scene::pMatrixID = 0;

GLuint Scene::cameraPositionVecID = 0;

GLuint Scene::cameraUnprojectionID = 0;

void Scene::onMouseMotion(double xpos, double ypos)
{
    camera->onMouseMotion(xpos, ypos);
    
    if(lastX == -1 && lastY == -1)
    {
        lastX = xpos;
        lastY = ypos;
    }
    else
    {
        dX = xpos - lastX;
        dY = ypos - lastY;
    }
}

void Scene::onMouseScroll(double xoffset, double yoffset)
{
    camera->onMouseWheel(xoffset, yoffset);
}

void Scene::onKey(int key, int scancode, int action, int mods)
{

}