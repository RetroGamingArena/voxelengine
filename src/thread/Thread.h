//
//  Thread.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 25/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#ifndef __Voxelengine__Thread__
#define __Voxelengine__Thread__

#include <stdio.h>
#include <thread>
#include <mutex>

#include "Task.h"

class Thread
{
    Task* task;
    std::mutex* mutex;
    
    static void run(Thread* thread);
    
    public:
        Thread()
        {
            mutex = new std::mutex;
        }
        void setTask(Task* task){this->task = task;}
        void start();
        bool isBusy();
};

#endif /* defined(__Voxelengine__Thread__) */
