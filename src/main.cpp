//
//  main.cpp
//  voxelengine
//
//  Created by Julien CAILLABET on 27/12/2014.
//  Copyright (c) 2014 Julien CAILLABET. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <time.h>
#include "engine/engine.h"

Engine* engine = Engine::getInstance();

int main(int argc, char **argv)
{
    //srand(time(NULL));
    engine->run();
    
    return 0;
}