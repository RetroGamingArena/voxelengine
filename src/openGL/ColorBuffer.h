//
//  ColorBuffer.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 29/12/2014.
//  Copyright (c) 2014 RGA. All rights reserved.
//

#ifndef __Voxelengine__ColorBuffer__
#define __Voxelengine__ColorBuffer__

#include <stdio.h>

#include "Buffer.h"

class ColorBuffer : public Buffer
{
    public:
        ColorBuffer(int vertexCount) : Buffer(vertexCount)
        {
            itemSize = 4;
            init();
        }
};

#endif /* defined(__Voxelengine__ColorBuffer__) */
