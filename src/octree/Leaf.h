//
//  Leaf.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 25/01/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#ifndef __Voxelengine__Leaf__
#define __Voxelengine__Leaf__

#include <stdio.h>

#include "OctreeEntry.h"

class Leaf : public OctreeEntry
{
    unsigned char leaf;
    
    public:
        Leaf(){};
        Leaf(unsigned char leaf){this->leaf=leaf;};
        unsigned char getLeaf(){return leaf;};
        void setLeaf(unsigned char leaf){this->leaf=leaf;};
        void invalidate();
        bool isCompressible(){ return false; };
        void setCube(int x, int y, int z, int size, unsigned char type);
        void setCubes(int x, int y, int z, int size, unsigned char* type);
        void bufferize(GlobalBuffer* buffer, float p, float q, float r, int size);
        unsigned char getAbs(int x, int y, int z, int size);
        int getCode(){return leaf;};
        void generate(WorldGenerator* generator, int x, int y, int z, int size);
        OctreeEntry* getOctreeEntryAbs(int x, int y, int z, int size);
};

#endif /* defined(__Voxelengine__Leaf__) */
