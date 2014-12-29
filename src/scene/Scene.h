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

#include "../../depends/glm/glm.hpp"

//#include "../depends/glm/glm.hpp"
#include "../../depends/glm/gtc/matrix_transform.hpp"

class Scene
{
    glm::mat4 projection;
    glm::mat4 view;
    glm::mat4 model;
    
    protected:
        glm::mat4 MVP;
        GLFWwindow* window;
        GLuint matrixID;
    
    public:
        Scene(GLFWwindow* window)
        {
            this->window = window;
            
            projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
            view       = glm::lookAt(
                                     glm::vec3(4,3,-3), // Camera is at (4,3,-3), in World Space
                                     glm::vec3(0,0,0), // and looks at the origin
                                     glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
                                     );
            model = glm::mat4(1.0f);
            MVP        = projection * view * model;
        }
        virtual void render() = 0;
        virtual void init() = 0;
};

#endif /* defined(__Voxelengine__Scene__) */
