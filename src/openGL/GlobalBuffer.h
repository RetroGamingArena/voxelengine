//
//  GlobalBuffer.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 04/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#ifndef __Voxelengine__GlobalBuffer__
#define __Voxelengine__GlobalBuffer__

#include <stdio.h>

#include "Buffer.h"

class GlobalBuffer : public Buffer<GLfloat>
{
    public:
        GlobalBuffer() : Buffer(vertexCount)
        {
            itemSize = 6;
        }
};

#endif /* defined(__Voxelengine__GlobalBuffer__) */
