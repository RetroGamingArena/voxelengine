//
//  LoadingUI.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 12/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#ifndef __Voxelengine__LoadingUI__
#define __Voxelengine__LoadingUI__

#include <stdio.h>

#include "UI.h"

class LoadingUI : public UI
{
    public:
        LoadingUI() : UI()
        {
            controls.push_back(new Label("Loading...", 20, 20));
        }
};

#endif /* defined(__Voxelengine__LoadingUI__) */
