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
#include "../UI/UI.h"
#include "../UI/DebugUI.h"
#include "../camera/TrackBallCamera.h"
#include "../../depends/glm/glm.hpp"
#include "../../depends/glm/gtc/matrix_transform.hpp"

class Scene
{
    protected:
        Camera* camera;
        GLfloat* lightpos;//[] = {.5, 1., 1., 0.};
        GLFWwindow* window;
    
        UI* ui;
    
    public:
        static GLuint matrixID;
        static GLuint mMatrixID;
        static GLuint vMatrixID;
        static GLuint pMatrixID;
    
        static GLuint cameraUnprojectionID;
    
        static GLuint cameraPositionVecID;
    
        Scene(GLFWwindow* window)
        {
            this->window = window;
            camera = new TrackBallCamera();
            
            lightpos = new GLfloat[4];
            lightpos[0] = 16;
            lightpos[1] = 3;
            lightpos[2] = 16;
            lightpos[3] = 0.;
            
            //ui = new DebugUI();
        }
        UI* getUI(){return ui;}
        Camera* getCamera(){return camera;}
        //GLfloat* getLightPos(){return lightpos;}
        virtual void onMouseMotion(double xpos, double ypos);
        virtual void onMouseScroll(double xoffset, double yoffset);
        virtual void render() = 0;
        virtual void init() = 0;
};

#endif /* defined(__Voxelengine__Scene__) */
