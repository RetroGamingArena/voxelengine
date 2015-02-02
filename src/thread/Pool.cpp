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
    for(int i = 0; i < threadCount; i++)
    {
        Task* task = buildTask();
        if(task != NULL)
        {
            Thread* thread = new Thread();
            thread->setTask(task);
            threads.push_back(thread);
        }
    }
    for(int i = 0; i < threads.size(); i++)
    {
        Thread* thread = threads[i];
        if(thread != NULL)
            thread->start();
    }
    work = new thread(Pool::run, this);
}

bool Pool::isRunning()
{
    for(int i = 0; i < threads.size(); i++)
    {
        if( threads[i] != NULL )
            if( threads[i]->isBusy() )
            {
                return true;
            }
            /*else
            {
                delete threads[i];
                threads.erase(threads.begin()+i);
                threads.insert(threads.begin()+i, NULL);
            }*/
    }
    return false;
}

void Pool::run(Pool* pool)
{
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