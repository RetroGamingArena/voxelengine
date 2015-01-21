//
//  ShaderLoader.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 29/12/2014.
//  Copyright (c) 2014 RGA. All rights reserved.
//

#ifndef __Voxelengine__ShaderLoader__
#define __Voxelengine__ShaderLoader__

#include <stdio.h>
#include <glew.h>
#include <GLFW/glfw3.h>

class ShaderLoader
{
    public:
        static GLuint load(const char * vertex_file_path,const char * fragment_file_path,const char * geometry_file_path);
};

#endif /* defined(__Voxelengine__ShaderLoader__) */
