//
//  IndiceBuffer.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 06/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#ifndef __Voxelengine__IndiceBuffer__
#define __Voxelengine__IndiceBuffer__

#include <stdio.h>

#include "Buffer.h"

class IndiceBuffer : public Buffer<unsigned int>
{
    public:
        IndiceBuffer() : Buffer(vertexCount)
        {
            itemSize = 1;
        }
};

#endif /* defined(__Voxelengine__IndiceBuffer__) */
