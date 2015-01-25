//
//  Thread.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 25/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include "Thread.h"

using namespace std;

void Thread::start()
{
    mutex->lock();
    thread* t = new thread(run, this);
}

void Thread::run(Thread* thread)
{
    if( thread->task != NULL)
        thread->task->run();
}

bool Thread::isBusy()
{
    if(mutex->try_lock())
    {
        mutex->unlock();
        return false;
    }
    return true;
}