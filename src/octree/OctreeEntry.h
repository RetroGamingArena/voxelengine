//
//  OctreeEntry.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 07/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#ifndef __Voxelengine__OctreeEntry__
#define __Voxelengine__OctreeEntry__

#include <stdio.h>

#include "../scene/VBOScene.h"
#include "../TemplateDebug.h"
#include "../world/generator/WorldGenerator.h"
class OctreeEntry
{
    protected:
        static int NODE;
    
    public:
        OctreeEntry()
        {
            //entries = 0;
            //drawn = false;
        }
        virtual ~OctreeEntry() {};
        virtual void invalidate() = 0;
        virtual bool isCompressible() = 0;
        virtual void setCube(int x, int y, int z, int size, unsigned char type) = 0;
        virtual void setCubes(int x, int y, int z, int size, unsigned char* type) = 0;
        virtual void bufferize(GlobalBuffer* buffer, float p, float q, float r, int size) = 0;
        virtual unsigned char getAbs(int x, int y, int z, int size) = 0;
        virtual OctreeEntry* getOctreeEntryAbs(int x, int y, int z, int size) = 0;
        virtual int getCode() = 0;
        virtual void generate(WorldGenerator* generator, int x, int y, int z, int size) = 0;
};

#endif /* defined(__Voxelengine__OctreeEntry__) */
