//
//  Item.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 16/02/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#ifndef __Voxelengine__Item__
#define __Voxelengine__Item__

#include <stdio.h>

#include "../../depends/glm/glm.hpp"
#include "../../depends/glm/gtc/matrix_transform.hpp"

using namespace glm;

class Item
{
    protected:
        double x;
        double y;
        double z;
    
        double ax;
        double ay;
        double az;
    
        double dx;
        double dy;
        double dz;
    
        double width;
        bool falling;
    
    public:
        Item(int x, int y, int z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
            
            this->ax = 0;
            this->ay = 0;
            this->az = 0;
            
            this->dx = 0;
            this->dy = 0;
            this->dz = 0;
            
            falling = false;
        }
        vec3 getposition(){return vec3(x,y,z);};
        vec3 getA(){return vec3(ax,ay,az);};
        vec3 getD(){return vec3(dx,dy,dz);};
    
        virtual void live(double dt) = 0;
        void setFalling(bool falling){this->falling = falling;};
    
        void setX(double x){this->x = x;};
        void setY(double y){this->y = y;};
        void setZ(double z){this->z = z;};
    
        void setDx(double dx){this->dx = dx;};
        void setDy(double dy){this->dy = dy;};
        void setDz(double dz){this->dz = dz;};
};

#endif /* defined(__Voxelengine__Item__) */
