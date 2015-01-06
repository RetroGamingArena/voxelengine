//
//  DebugUI.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 05/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#ifndef __Voxelengine__DebugUI__
#define __Voxelengine__DebugUI__

#include <stdio.h>

#include "UI.h"

class DebugUI : public UI
{
    public:
        DebugUI() : UI()
        {
            controls.push_back(new Label("Minequest - FPS: ", 20, 20));
        }
};

#endif /* defined(__Voxelengine__DebugUI__) */
