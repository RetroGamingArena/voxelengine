//
//  Player.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 16/02/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#ifndef __Voxelengine__Player__
#define __Voxelengine__Player__

#include <stdio.h>

#include "../../depends/glm/glm.hpp"
#include "../../depends/glm/gtc/matrix_transform.hpp"

#include "Item.h"

#define PI 3.14159265

class Player : public Item
{
    double lx;
    double ly;
    double lz;
    
    double _angleY;
    double _angleZ;
    
    public:
        Player() : Item(8,64,8)
        {
            _angleY = 0;
            _angleZ = 0;
            width = 50;
            updateLook();
        }
        vec3 getLook(){return vec3(lx,ly,lz);};
        double getAngleY(){return _angleY;};
        double getAngleZ(){return _angleZ;};
    
        void setAngleY(double _angleY){this->_angleY = _angleY;updateLook();};
        void setAngleZ(double _angleZ){this->_angleZ = _angleZ;updateLook();};
        void updateLook();
    
        void live(double dt);
};

#endif /* defined(__Voxelengine__Player__) */
