//
//  Camera.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 01/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include <glew.h>
#include <GLFW/glfw3.h>

#include "Camera.h"

glm::mat4 Camera::getMVP()
{
    return MVP;
}

void Camera::look()
{
    // glfwGetTime is called only once, the first time this function is called
    static double lastTime = glfwGetTime();
    
    double currentTime = glfwGetTime();
    
    float FoV = initialFoV;// - 5 * glfwGetMouseWheel(); // Now GLFW 3 requires setting up a callback for this. It's a bit too complicated for this beginner's tutorial, so it's disabled instead.
    
    // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
    projection = glm::perspective(FoV, 4.0f / 4.0f, 0.0009f, 200.0f);
    // Camera matrix
    view       = glm::lookAt(
                             getPosition(),           // Camera is here
                             getCenter(), // and looks here : at the same position, plus "direction"
                             getUp()                  // Head is up (set to 0,-1,0 to look upside-down)
                             );
    
    MVP = projection * view * model;
    
    glm::vec3 v2 = unproject(0, 0);
    glm::vec3 v1 = unproject(1024.0, 0);
    glm::vec3 v4 = unproject(0, 768.0);
    glm::vec3 v3 = unproject(1024.0, 1024.0);//768.0);
    
    unprojection[0] = v1;
    unprojection[1] = v2;
    unprojection[2] = v3;
    unprojection[3] = v4;
    
    // For the next frame, the "last time" will be "now"
    lastTime = currentTime;
}

void Camera::computeMatricesFromInputs()
{
    
    // glfwGetTime is called only once, the first time this function is called
    static double lastTime = glfwGetTime();
    
    // Compute time difference between current and last frame
    double currentTime = glfwGetTime();
    float deltaTime = float(currentTime - lastTime);
    
    // Get mouse position

    /*sin(horizontalAngle - 3.14f/2.0f),
    0,
    cos(horizontalAngle - 3.14f/2.0f)
    );*/
    
    //glm::vec3 up = glm::cross( right, direction );
    
    float FoV = initialFoV;// - 5 * glfwGetMouseWheel(); // Now GLFW 3 requires setting up a callback for this. It's a bit too complicated for this beginner's tutorial, so it's disabled instead.
    
    // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
    projection = glm::perspective(FoV, 4.0f / 3.0f, 0.1f, 100.0f);
    // Camera matrix
    view       = glm::lookAt(
                                   getPosition(),           // Camera is here
                                   getCenter(), // and looks here : at the same position, plus "direction"
                                   getUp()                  // Head is up (set to 0,-1,0 to look upside-down)
                                   );
    
    // For the next frame, the "last time" will be "now"
    lastTime = currentTime;
}

glm::vec3 Camera::unproject(int x, int y)
{
    glm::vec3 pos = glm::vec3(x, y, 0.0f);
    glm::vec4 viewportdata = glm::vec4(0.0f, 0.0f, 1024.0f, 1024.0);//768.0f);
    
    return glm::unProject(pos, view*model, projection, viewportdata);
}