//
//  World.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 28/12/2014.
//  Copyright (c) 2014 RGA. All rights reserved.
//

#ifndef __Voxelengine__World__
#define __Voxelengine__World__

#include <stdio.h>
#include <vector>

#include "Chunk.h"
#include "../scene/VBOScene.h"
#include "generator/WorldGenerator.h"
#include "generator/PerlinGenerator.h"

using namespace std;

class World
{
    vector<Chunk*> chunks;
    WorldGenerator* generator;
    
    public:
        World()
        {
            generator = new PerlinGenerator();
            
            for(int p=-1; p<=1; p++)
                for(int r=-1; r<=1; r++)
                {
                    Chunk* chunk = new Chunk(p,0,r);
                    chunk->generate(generator);
                    chunks.push_back(chunk);
                }
            
        }
        vector<Chunk*> getChunks(){return chunks;}
        void bufferize(VBOScene* scene);
        int cubeCount();
};

#endif /* defined(__Voxelengine__World__) */
