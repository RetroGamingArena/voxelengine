//
//  Buffer.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 29/12/2014.
//  Copyright (c) 2014 RGA. All rights reserved.
//

#ifndef __Voxelengine__Buffer__
#define __Voxelengine__Buffer__

#include <glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <vector>

template< typename T>
class Buffer
{
    protected:
        std::vector<T>* data;
        int vertexCount;
        int itemSize;

    public:
        Buffer(int vertexCount)
        {
            this->vertexCount = vertexCount;
            data = new std::vector<T>();
        }
        std::vector<T>* getData(){return data;};
};

#endif /* defined(__Voxelengine__Buffer__) */
