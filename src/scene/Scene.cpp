//
//  Scene.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 28/12/2014.
//  Copyright (c) 2014 RGA. All rights reserved.
//

#include "Scene.h"

GLuint Scene::matrixID = 0;

void Scene::onMouseMotion(double xpos, double ypos)
{
    camera->onMouseMotion(xpos, ypos);
}