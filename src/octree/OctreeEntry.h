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

class OctreeEntry
{
    protected:
        static int NODE;
        //static int LEAF;
        //bool drawn;
        //OctreeEntry** entries;
    
        //int level=0;
    
    public:
        OctreeEntry()
        {
            //entries = 0;
            //drawn = false;
        }
    virtual ~OctreeEntry() {};
        //{
            /*if( this->entries != NULL )
                for(int i = 0; i < 8; i++)
                {
                    if( this->entries[i] != NULL )
                    {
                        delete this->entries[i];
                        //TemplateDebug::debug();
                        this->entries[i] = NULL;
                    }
                }
            delete[] this->entries;*/
        //}
        //void split();
    
        //bool isDrawn(){return drawn;};
        //void setDrawn(bool drawn){this->drawn=drawn;};
        //OctreeEntry** getEntries(){return entries;};
        /*OctreeEntry* get(int x, int y, int z);
        OctreeEntry* getAbs(int x, int y, int z, int size);*/
        //void setLevel(int level){this->level=level;};
        /*void setCube(int x, int y, int z, int size, unsigned char type);*/
        virtual void invalidate() = 0;
        virtual bool isCompressible() = 0;
        virtual void setCube(int x, int y, int z, int size, unsigned char type) = 0;
        virtual void bufferize(GlobalBuffer* buffer, float p, float q, float r, int size) = 0;
        virtual unsigned char getAbs(int x, int y, int z, int size) = 0;
        virtual int getCode() = 0;
    
};

#endif /* defined(__Voxelengine__OctreeEntry__) */
