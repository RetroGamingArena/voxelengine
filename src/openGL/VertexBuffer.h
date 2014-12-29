//
//  VertexBuffer.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 29/12/2014.
//  Copyright (c) 2014 RGA. All rights reserved.
//

#ifndef __Voxelengine__VertexBuffer__
#define __Voxelengine__VertexBuffer__

#include <stdio.h>

#include "Buffer.h"

class VertexBuffer : public Buffer
{
    public:
        VertexBuffer(int vertexCount) : Buffer(vertexCount)
        {
            itemSize = 3;
            init();
        }
};

#endif /* defined(__Voxelengine__VertexBuffer__) */
