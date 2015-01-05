//
//  Control.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 05/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#ifndef __Voxelengine__Control__
#define __Voxelengine__Control__

#include <stdio.h>

class Control
{
    protected:
        int x;
        int y;
    
    public:
        Control(int x, int y)
        {
            this->x = x;
            this->y = y;
        }
        int getX(){return x;};
        int getY(){return y;};
        virtual void render(/*UI* ui*/) = 0;
};

#endif /* defined(__Voxelengine__Control__) */
