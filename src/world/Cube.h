//
//  Cube.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 29/12/2014.
//  Copyright (c) 2014 RGA. All rights reserved.
//

#ifndef __Voxelengine__Cube__
#define __Voxelengine__Cube__

#include <stdio.h>
#include "../scene/VBOScene.h"

class Cube
{
    unsigned char x;
    unsigned char y;
    unsigned char z;
    
    unsigned char type;

    static void bufferizeSquare(VBOScene* scene, float x1, float y1, float z1, float x2, float y2, float z2);
    static void bufferizeSquareColor(VBOScene* scene, float r, float g, float b);
    
    public:
        static float size;
        Cube(float x, float y, float z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        };
        static glm::vec3 getCoords(int index);
        static int getIndex(int x, int y, int z);
        unsigned char getX(){return x;};
        unsigned char getY(){return y;};
        unsigned char getZ(){return z;};
        unsigned char getType(){return type;};
        void setType(unsigned char type){this->type = type;};
        void bufferize(VBOScene* scene, float x, float y, float z);
};

#endif /* defined(__Voxelengine__Cube__) */
