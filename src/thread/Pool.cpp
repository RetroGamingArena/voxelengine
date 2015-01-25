//
//  Pool.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 25/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include "Pool.h"

using namespace std;

void Pool::registerThread(Thread* thread)
{
    threads.push_back(thread);
}

void Pool::start()
{
    work = new thread(Pool::run, this);
}

bool Pool::isRunning()
{
    return false;
}

void Pool::run(Pool* pool)
{
    for(int i = 0; i < pool->threadCount; i++)
    {
        Thread* thread = new Thread();
        Task* task = pool->buildTask();
        thread->setTask(task);
        pool->threads.push_back(thread);
        thread->start();
    }
    
    while (pool->hasNext())
    {
        Task* task = pool->buildTask();
        while(task != NULL )
        {
            for(int i = 0; i < pool->threadCount; i++)
            {
                if( !pool->threads[i]->isBusy() )
                {
                    pool->threads[i]->setTask(task);
                    pool->threads[i]->start();
                    task = pool->buildTask();
                    break;
                }
            }
        }
    }
}