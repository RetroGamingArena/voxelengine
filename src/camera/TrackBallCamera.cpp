//
//  TrackBallCamera.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 01/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include <glew.h>
#include <GLFW/glfw3.h>

#include "TrackBallCamera.h"

void TrackBallCamera::onMouseMotion(double xpos, double ypos)
{
    double dx = xpos-oldX;
    double dy = xpos-oldY;
    
    if (_hold) //si nous maintenons le bouton gauche enfoncé
    {
        // TODO dXY
        _angleZ += dx*_motionSensivity; //mouvement sur X de la souris -> changement de la rotation horizontale
        _angleY += dy*_motionSensivity; //mouvement sur Y de la souris -> changement de la rotation verticale
        //pour éviter certains problèmes, on limite la rotation verticale à des angles entre -90° et 90°
        /*if (_angleY > 90)
            _angleY = 90;
        else if (_angleY < -90)
            _angleY = -90;*/
    }
    
    oldX = xpos;
    oldY = ypos;
}

void TrackBallCamera::onMouseButton(int button, int action)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT)
    {
        if ((_hold)&&(action == GLFW_RELEASE))
        {
            _hold = false;
        }
        else if ((!_hold)&&(action == GLFW_PRESS))
        {
            _hold = true;
        }
    }
}

void TrackBallCamera::onKeyboard()
{
    
}

void TrackBallCamera::onMouseWheel(double xoffset, double yoffset)
{
    if (yoffset < 0) //coup de molette vers le haut
    {
        _distance -= _scrollSensivity; //on zoome, donc rapproche la caméra du centre
        if (_distance < 0.1) //distance minimale, à changer si besoin (avec un attribut par exemple)
            _distance = 0.1;
    }
    else if (yoffset > 0) //coup de molette vers le bas
    {
        _distance += _scrollSensivity; //on dézoome donc éloigne la caméra
    }
}

glm::vec3 TrackBallCamera::getPosition()
{
    glm::vec3 position(
                        cos(_angleY) * sin(_angleZ) * _distance,
                        sin(_angleY) * _distance,
                        cos(_angleY) * cos(_angleZ) * _distance
                        );
    
    return position;
}

glm::vec3 TrackBallCamera::getCenter()
{
    return glm::vec3(0,0,0);
}

glm::vec3 TrackBallCamera::getUp()
{
    glm::vec3 direction(
                        cos(_angleY) * sin(_angleZ),
                        sin(_angleY),
                        cos(_angleY) * cos(_angleZ)
                        );
    
    glm::vec3 right = glm::vec3(
                                sin(_angleZ - 3.14f/2.0f),
                                0,
                                cos(_angleZ - 3.14f/2.0f)
                                );
    
    return glm::cross( right, direction );
}
