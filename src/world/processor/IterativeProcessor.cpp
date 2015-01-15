//
//  IterativeProcessor.cpp
//  Voxelengine
//
//  Created by Julien CAILLABET on 15/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#include "IterativeProcessor.h"

void IterativeProcessor::bufferize(VBOScene* scene, World* world)
{    
    for(int i=0; i < world->getChunks().size() ; i++)
    {
        world->getChunks()[i]->bufferize(scene);
    }
}