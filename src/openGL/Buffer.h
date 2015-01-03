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

class Buffer
{
    protected:
        std::vector<GLfloat>* data;
        int vertexCount;
        int itemSize;
        //int cursor;

    public:
        Buffer(int vertexCount)
        {
            this->vertexCount = vertexCount;
            //this->cursor = 0;
            data = new std::vector<GLfloat>();
        }
        std::vector<GLfloat>* getData(){return data;};
        int getSize(){return itemSize * vertexCount;};
        //int getCursor(){return cursor;};
        //void setCursor(int cursor){this->cursor = cursor;};
        void init();
};

#endif /* defined(__Voxelengine__Buffer__) */
