//
//  LoadingScene.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 12/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#ifndef __Voxelengine__LoadingScene__
#define __Voxelengine__LoadingScene__

#include <stdio.h>
#include <thread>
#include <mutex>

#include "VBOScene.h"
#include "../UI/LoadingUI.h"

class LoadingScene : public VBOScene
{
    std::thread* thread;
    static std::mutex* mutex;

    public:
        LoadingScene(GLFWwindow* window) : VBOScene(window)
        {
            this->ui = new LoadingUI();
            thread = NULL;
        }
        void render();
        static void initWorld();
};

#endif /* defined(__Voxelengine__LoadingScene__) */
