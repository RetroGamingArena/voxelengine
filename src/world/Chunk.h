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

using namespace std;

class Chunk
{
    vector<Cube*> cubes;
    
    public:
        Chunk()
        {
            cubes.push_back(new Cube());
        }
};

#endif /* defined(__Voxelengine__Chunk__) */
