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
    
    float lowerPBound;
    float upperPBound;
    float lowerRBound;
    float upperRBound;
    
    public:
        static int size;
        World()
        {
            generator = new PerlinGenerator();
            
            for(int p=-size; p<=size; p++)
                for(int r=-size; r<=size; r++)
                {
                    Chunk* chunk = new Chunk(p,0,r);
                    chunk->generate(generator);
                    chunks.push_back(chunk);
                }
        }
        vector<Chunk*> getChunks(){return chunks;}
    
        void bufferize(VBOScene* scene);
        int cubeCount();
        Chunk* getPointedChunk(float x, float y, float z);
        OctreeEntry<unsigned char>* getPointedCube(float x, float y, float z);
};

#endif /* defined(__Voxelengine__World__) */
