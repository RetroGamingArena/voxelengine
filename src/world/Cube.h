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
    float x1;
    float y1;
    float z1;

    float x2;
    float Y2;
    float z2;

    public:
        Cube()
        {
            x1 = -1.0;
            y1 = -1.0;
            z1 = -1.0;
            
            x2 = 1.0;
            Y2 = 1.0;
            z2 = 1.0;
        }
        void bufferize(VBOScene* scene);
};

#endif /* defined(__Voxelengine__Cube__) */
