//
//  Pool.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 25/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#ifndef __Voxelengine__Pool__
#define __Voxelengine__Pool__

#include <stdio.h>
#include <vector>
#include <thread>

#include "Thread.h"
#include "Task.h"

class Pool
{
    bool running;
    std::thread* work;
    static void run(Pool* pool);

    protected:
        int threadCount;
        std::vector<Thread*> threads;
        std::mutex* mutex;

    public:
        Pool()
        {
            running=false;
            mutex=new std::mutex();
        }
        void registerThread(Thread* thread);
        void start();
        bool isRunning();
        virtual Task* buildTask() = 0;
        virtual bool hasNext() = 0;
};

#endif /* defined(__Voxelengine__Pool__) */
