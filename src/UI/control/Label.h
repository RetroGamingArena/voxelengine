//
//  Label.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 05/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#ifndef __Voxelengine__Label__
#define __Voxelengine__Label__

#include <stdio.h>
#include <string.h>

#include "Control.h"

class Label : public Control
{
    char* caption;
    
    public:
        Label(const char* caption, int x, int y) : Control(x, y)
        {
            this->caption = new char[strlen(caption)];
            strcpy(this->caption, caption);
        }
        char* getCaption(){return caption;};
        void render(/*UI* ui*/);
};

#endif /* defined(__Voxelengine__Label__) */
