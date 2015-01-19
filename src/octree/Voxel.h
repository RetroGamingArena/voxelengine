//
//  Voxel.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 19/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#ifndef __Voxelengine__Voxel__
#define __Voxelengine__Voxel__

#include <stdio.h>

#include "Octree.h"

class Voxel : public Octree<unsigned char>
{
    public:
        unsigned char value;
};

#endif /* defined(__Voxelengine__Voxel__) */
