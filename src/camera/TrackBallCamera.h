//
//  TrackBallCamera.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 01/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#ifndef __Voxelengine__TrackBallCamera__
#define __Voxelengine__TrackBallCamera__

#include <stdio.h>

#include "Camera.h"

class TrackBallCamera : public Camera
{
    double oldX;
    double oldY;
    
    double _distance;
    double _angleY;
    double _angleZ;
    bool _hold;
    double _scrollSensivity;
    double _motionSensivity;
    
    void onMouseMotion(double xpos, double ypos);
    void onMouseButton(int button, int action);
    void onKeyboard();
    void onMouseWheel(double xoffset, double yoffset);
    
    virtual glm::vec3 getPosition();
    virtual glm::vec3 getCenter();
    virtual glm::vec3 getUp();
    
    public:
        TrackBallCamera() : Camera()
        {
            _hold = false; //au départ on part du principe que le bouton n'est pas maintenu
            _angleY = 3.14/8;
            _angleZ = 3.14/4;
            _distance = 70; //distance initiale de la caméra avec le centre de la scène
            _motionSensivity = 0.3;
            _scrollSensivity = 1;
            
            oldX=0;
            oldY=0;
            
            view       = glm::lookAt(
                                     getPosition(),           // Camera is here
                                     getCenter(), // and looks here : at the same position, plus "direction"
                                     getUp()                  // Head is up (set to 0,-1,0 to look upside-down)
                                     );
        }
};

#endif /* defined(__Voxelengine__TrackBallCamera__) */
