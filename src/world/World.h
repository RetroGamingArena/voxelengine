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
#include "../thread/Pool.h"

using namespace std;

class World : public Pool
{
    vector<Chunk*> chunks;
    WorldGenerator* generator;
    int chunkIndice;
    
    float lowerPBound;
    float upperPBound;
    float lowerRBound;
    float upperRBound;
    
    public:
        static int size;
        static void bufferizeEntry(GlobalBuffer* buffer, unsigned char, float p, float q, float r, float width);

        World()
        {
            chunkIndice = 0;
            generator = new PerlinGenerator();
            
            for(int p=-size; p<=size; p++)
                for(int r=-size; r<=size; r++)
                {
                    Chunk* chunk = new Chunk(p,0,r);
                    //chunk->generate(generator);
                    chunks.push_back(chunk);
                }
            
            threadCount = 5;
            this->start();
            while(isRunning()){}
        }
        Task* buildTask();
        bool hasNext();
        vector<Chunk*> getChunks(){return chunks;}
        void bufferize(VBOScene* scene);
        int cubeCount();
        Chunk* getPointedChunk(float x, float y, float z);
        OctreeEntry* getPointedCube(float x, float y, float z);
        bool isCubeVisible(int x, int y, int z,int size);
        unsigned char getCube(int x, int y, int z);
};

#endif /* defined(__Voxelengine__World__) */
