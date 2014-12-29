//
//  Chunk.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 29/12/2014.
//  Copyright (c) 2014 RGA. All rights reserved.
//

#ifndef __Voxelengine__Chunk__
#define __Voxelengine__Chunk__

#include <stdio.h>
#include <vector>

#include "Cube.h"
#include "../scene/VBOScene.h"

using namespace std;

class Chunk
{
    float x;
    float y;
    float z;
    
    vector<Cube*> cubes;
    
    public:
        Chunk()
        {
            x=0;
            y=0;
            z=0;

            cubes.push_back(new Cube(0, 0, 0));
        }
        vector<Cube*> getCubes(){return cubes;}
        void bufferize(VBOScene* scene);    
};

#endif /* defined(__Voxelengine__Chunk__) */
