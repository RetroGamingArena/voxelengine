//
//  Player.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 16/02/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include "Player.h"

#include "../world/World.h"
#include "../engine/engine.h"

#define G 9.81

void Player::updateLook()
{
    double angleY = _angleY*PI / 180.0;
    double angleZ = _angleZ*PI / 180.0;
    
    lx = x + cos(angleY);// * sin(angleZ);
    ly = y;//y + sin(_angleY)                * 10;
    lz = z + sin(angleY);// * cos(angleZ);
}

void Player::live(double dt)
{
    World* world = Engine::getInstance()->getWorld();
    
    if(dx>0 || dy>0 || dz>0)
    {
        unsigned char cube = world->getCube((x+dx)*Chunk::subsize, (y+dy)*Chunk::subsize, (z+dz)*Chunk::subsize);
        if(cube == 0)
        {
            x+=dx;
            y+=dy;
            z+=dz;
        }
    }
    
    if(falling)
    {
        unsigned char cube = world->getCube(x*Chunk::subsize, y*Chunk::subsize, z*Chunk::subsize);
        if(cube == 0)
        {
            double _y = 0.5*G*dt*dt * 0.5;
            unsigned char dcube = world->getCube(x*Chunk::subsize, (y-_y)*Chunk::subsize, z*Chunk::subsize);
            if(dcube == 0)
            {
                y = y-_y;
                updateLook();
            }
            else
                falling = false;
        }
        else
            falling = false;
    }
}