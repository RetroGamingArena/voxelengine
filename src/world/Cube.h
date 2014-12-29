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
    static float size;
    
    float x;
    float y;
    float z;

    static void bufferizeSquare(VBOScene* scene, int x1, int y1, int z1, int x2, int y2, int z2);
    static void bufferizeSquareColor(VBOScene* scene, int r, int g, int b);
    
    public:
        Cube(float x, float y, float z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }
        void bufferize(VBOScene* scene, float x, float y, float z);
};

#endif /* defined(__Voxelengine__Cube__) */
