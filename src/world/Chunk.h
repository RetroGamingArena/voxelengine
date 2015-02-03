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
#include <map>

#include "Cube.h"
#include "../scene/VBOScene.h"
#include "generator/WorldGenerator.h"

#include "../octree/Octree.h"
#include "../octree/Voxel.h"

using namespace std;

class Chunk
{
    float p;
    float q;
    float r;
    
    GlobalBuffer* buffer;
    Octree* o;

    public:
        static int size;
        static int subsize;
        Chunk(float p, float q, float r)
        {
            this->buffer = new GlobalBuffer();
            
            this->p=p;
            this->q=q;
            this->r=r;
            
            this->o = new Octree();
            o->setSize(Chunk::size*Chunk::subsize);
            o->setSubSize(Chunk::subsize);
            
            o->p=p;
            o->q=q;
            o->r=r;
        }
        float getP(){return p;};
        float getQ(){return q;};
        float getR(){return r;};
        Octree* getOctree(){return o;};
        void bufferize(GlobalBuffer* scene);
        void generate(WorldGenerator* generator);
        bool contains(float x, float y, float z);
        GlobalBuffer* getBuffer(){return buffer;}
};

#endif /* defined(__Voxelengine__Chunk__) */
