//
//  Camera.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 01/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#ifndef __Voxelengine__Camera__
#define __Voxelengine__Camera__

#include <stdio.h>

#include "../../depends/glm/glm.hpp"
#include "../../depends/glm/gtc/matrix_transform.hpp"

class Camera
{
    glm::mat4 projection;
    glm::mat4 model;
    glm::mat4 MVP;
    
    glm::mat4x3 unprojection;
    
    glm::vec3 position = glm::vec3( 0, 0, 5 );
    float horizontalAngle = 3.14f;
    float verticalAngle = 0.0f;
    float initialFoV = 70.0f;
    
    float speed = 3.0f; 
    float mouseSpeed = 0.005f;
    
    protected:
        glm::mat4 view;
        double oldX;
        double oldY;
    
    public:
        Camera()
        {
            projection = glm::perspective(70.0f, 4.0f / 4.0f, 0.001f, 200.0f);
            view       = glm::lookAt(
                                     glm::vec3(4,3,-3), // Camera is at (4,3,-3), in World Space
                                     glm::vec3(0,0,0), // and looks at the origin
                                     glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
                                     );
            model = glm::mat4(1.0f);
            MVP = projection * view * model;
        }
        virtual void onMouseMotion(double xpos, double ypos) = 0;
        virtual void onMouseButton(int button, int action) = 0;
        virtual void onKeyboard() = 0;
        virtual void onMouseWheel(double xoffset, double yoffset) = 0;
        void look();
    
        virtual glm::vec3 getPosition() = 0;
        virtual glm::vec3 getCenter() = 0;
        virtual glm::vec3 getUp() = 0;
    
        void computeMatricesFromInputs();
        glm::mat4 getMVP();
    
        glm::mat4x3 getUnprojection(){return unprojection;};
        glm::mat4 getProjection(){return projection;};
        glm::mat4 getModel(){return model;};
        glm::mat4 getView(){return view;};
        glm::vec3 unproject(int x, int y);
};

#endif /* defined(__Voxelengine__Camera__) */
