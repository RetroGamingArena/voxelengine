//
//  PerlinGenerator.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 02/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#ifndef __Voxelengine__PerlinGenerator__
#define __Voxelengine__PerlinGenerator__

#include <stdio.h>
#include <noise/noise.h>
#include "noiseutils.h"

#include "WorldGenerator.h"

using namespace noise;

class PerlinGenerator : public WorldGenerator
{
    module::Perlin module;
    utils::NoiseMap heightMap;
    utils::NoiseMapBuilderPlane heightMapBuilder;
    
    float lowerXBound;
    float upperXBound;
    float lowerYBound;
    float upperYBound;
    
    int destSize;
    
    public:
        PerlinGenerator()
        {
            lowerXBound = 2.0;
            upperXBound = 6.0;
            lowerYBound = 1.0;
            upperYBound = 5.0;
            
            destSize = 224;
            
            //int seed = rand()*100.0/RAND_MAX - (int)(rand()*100.0/RAND_MAX);
            //module.SetSeed(seed);
            
            heightMapBuilder.SetSourceModule (module);
            heightMapBuilder.SetDestNoiseMap (heightMap);
            heightMapBuilder.SetDestSize (destSize, destSize);
            heightMapBuilder.SetBounds (lowerXBound, upperXBound, lowerYBound, upperYBound);
            heightMapBuilder.Build ();
        }
        float getY(float x, float y);
};

#endif /* defined(__Voxelengine__PerlinGenerator__) */
