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
    
    public:
        PerlinGenerator()
        {
            heightMapBuilder.SetSourceModule (module);
            heightMapBuilder.SetDestNoiseMap (heightMap);
            heightMapBuilder.SetDestSize (256, 256);
            heightMapBuilder.SetBounds (2.0, 6.0, 1.0, 5.0);
            heightMapBuilder.Build ();
        }
        float getY(float x, float y);
};

#endif /* defined(__Voxelengine__PerlinGenerator__) */
