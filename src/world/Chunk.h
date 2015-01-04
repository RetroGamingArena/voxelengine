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
#include <vector>

#include "Cube.h"
#include "../scene/VBOScene.h"
#include "generator/WorldGenerator.h"

using namespace std;

class Chunk
{
    float p;
    float q;
    float r;
    
    vector<Cube*> cubes;

    public:
        static int size;
        Chunk(float p, float q, float r)
        {
            this->p=p;
            this->q=q;
            this->r=r;

            /*cubes.push_back(new Cube(0, 0, 0));
            cubes.push_back(new Cube(1, 0, 0));
            cubes.push_back(new Cube(0, 0, 1));
            cubes.push_back(new Cube(0, 1, 0));*/
        }
        vector<Cube*> getCubes(){return cubes;}
        void bufferize(VBOScene* scene);
        void generate(WorldGenerator* generator);
        bool isCubeVisible();
};

#endif /* defined(__Voxelengine__Chunk__) */
