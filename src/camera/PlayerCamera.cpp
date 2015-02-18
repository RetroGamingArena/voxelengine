//
//  PlayerCamera.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 16/02/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include "PlayerCamera.h"

void PlayerCamera::onMouseMotion(double xpos, double ypos)
{
    //int x = xpos;
}

void PlayerCamera::onMouseButton(int button, int action)
{
    
}

void PlayerCamera::onKeyboard()
{
    
}

void PlayerCamera::onMouseWheel(double xoffset, double yoffset)
{
    
}

glm::vec3 PlayerCamera::getPosition()
{
    glm::vec3 position = player->getposition();
    position.y+=2;
    return position;
}

glm::vec3 PlayerCamera::getCenter()
{
    glm::vec3 look = player->getLook();
    look.y+=2;
    return look;
}

glm::vec3 PlayerCamera::getUp()
{
    return glm::vec3(0,1,0);
}