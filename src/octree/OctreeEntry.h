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
    bool drawn;
    
    protected:
        OctreeEntry<T>** entries;
        T leaf;
        int level=0;
    
    public:
        OctreeEntry()
        {
            entries = 0;
            drawn = false;
        }
        ~OctreeEntry()
        {
        
        }
        void split();
        T getLeaf(){return leaf;};
        void setLeaf(T leaf){this->leaf=leaf;};
        bool isDrawn(){return drawn;};
        void setDrawn(bool drawn){this->drawn=drawn;};
        OctreeEntry<T>** getEntries(){return entries;};
        OctreeEntry<T>* get(int x, int y, int z);
        OctreeEntry<T>* getAbs(int x, int y, int z, int size);
        void setLevel(int level){this->level=level;};
        void setCube(int x, int y, int z, int size, T type);
        void invalidate();
};

#endif /* defined(__Voxelengine__OctreeEntry__) */
