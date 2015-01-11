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

template<typename T>
class OctreeEntry
{
    protected:
        OctreeEntry<T>** entries;
        T leaf;
        int level=0;
    
    public:
        OctreeEntry()
        {
            entries = 0;
        }
        void split();
        T getLeaf(){return leaf;};
        void setLeaf(T leaf){this->leaf=leaf;};
        OctreeEntry<T>** getEntries(){return entries;};
        OctreeEntry<T>* get(int x, int y, int z);
        OctreeEntry<T>* getAbs(int x, int y, int z, int size);
        void setLevel(int level){this->level=level;};
        void setCube(int x, int y, int z, int size, unsigned char type);
};

#endif /* defined(__Voxelengine__OctreeEntry__) */
