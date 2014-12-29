//
//  World.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 28/12/2014.
//  Copyright (c) 2014 RGA. All rights reserved.
//

#ifndef __Voxelengine__World__
#define __Voxelengine__World__

#include <stdio.h>
#include <vector>

#include "Chunk.h"
#include "../scene/VBOScene.h"

using namespace std;

class World
{
    vector<Chunk*> chunks;
    
    public:
        World()
        {
            chunks.push_back(new Chunk());
        }
        vector<Chunk*> getChunks(){return chunks;}
        void bufferize(VBOScene* scene);
};

#endif /* defined(__Voxelengine__World__) */
