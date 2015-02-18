//
//  PlayerCamera.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 16/02/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#ifndef __Voxelengine__PlayerCamera__
#define __Voxelengine__PlayerCamera__

#include <stdio.h>

#include "Camera.h"
#include "Player.h"

class PlayerCamera : public Camera
{
    Player* player;
    
    public:
        void onMouseMotion(double xpos, double ypos);
        void onMouseButton(int button, int action);
        void onKeyboard();
        void onMouseWheel(double xoffset, double yoffset);
    
        glm::vec3 getPosition();
        glm::vec3 getCenter();
        glm::vec3 getUp();
    
        PlayerCamera(Player* player)
        {
            this->player = player;
        }
};

#endif /* defined(__Voxelengine__PlayerCamera__) */
