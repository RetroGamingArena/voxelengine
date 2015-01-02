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

#include "../camera/Camera.h"
#include "../camera/TrackBallCamera.h"
#include "../../depends/glm/glm.hpp"
#include "../../depends/glm/gtc/matrix_transform.hpp"

class Scene
{
    Camera* camera;
    
    protected:
        GLFWwindow* window;
        GLuint matrixID;
    
    public:
        Scene(GLFWwindow* window)
        {
            this->window = window;
            camera = new TrackBallCamera();
            //MVP    = camera->getMVP();//projection * view * model;
        }
        Camera* getCamera(){return camera;}
        virtual void render() = 0;
        virtual void init() = 0;
};

#endif /* defined(__Voxelengine__Scene__) */
