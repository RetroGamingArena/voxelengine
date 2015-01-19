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
#include "../octree/Octree.cpp"
#include "../octree/Voxel.h"

using namespace std;

class Chunk
{
    float p;
    float q;
    float r;
    
    Octree<Voxel*>* o;

    public:
        static int size;
        Chunk(float p, float q, float r)
        {
            this->p=p;
            this->q=q;
            this->r=r;
            
            this->o = new Octree<Voxel*>();
            o->setSize(Chunk::size);
        }
        float getP(){return p;};
        float getQ(){return q;};
        float getR(){return r;};
        Octree<Voxel*>* getOctree(){return o;};
        void bufferize(VBOScene* scene);
        void generate(WorldGenerator* generator);
        bool contains(float x, float y, float z);
};

#endif /* defined(__Voxelengine__Chunk__) */
