//
//  VoxelScene.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 28/12/2014.
//  Copyright (c) 2014 RGA. All rights reserved.
//

#ifndef __Voxelengine__VoxelScene__
#define __Voxelengine__VoxelScene__

#include <stdio.h>
#include <thread>
#include <mutex>

#include "VBOScene.h"

class VoxelScene : public VBOScene
{
    std::thread* thread;
    static std::mutex* mutex;
    
    public:
        VoxelScene(GLFWwindow* window) : VBOScene(window)
        {
            ui = new DebugUI();
            thread = NULL;
        }
        void init();
        void onMouseScroll(double xoffset, double yoffset);
        void onMouseMotion(double xpos, double ypos);
        void render();
        static void bufferize(VoxelScene* voxelScene);
};

#endif /* defined(__Voxelengine__VoxelScene__) */
