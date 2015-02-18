//
//  GameScene.h
//  Voxelengine
//
//  Created by Julien CAILLABET on 16/02/2015.
//  Copyright (c) 2015 RGA. All rights reserved.
//

#ifndef __Voxelengine__GameScene__
#define __Voxelengine__GameScene__

#include <stdio.h>
#include <vector>

#include "VoxelScene.h"

#include "../item/Item.h"
#include "../item/Player.h"
#include "../camera/PlayerCamera.h"

using namespace std;

class GameScene : public VoxelScene
{
    vector<Item*> items;
    
    public:
        GameScene(GLFWwindow* window, Player* player) : VoxelScene(window)
        {
            items.push_back(player);
            //delete camera;
            //camera = new PlayerCamera(player);
        }
        void onMouseMotion(double xpos, double ypos);
};

#endif /* defined(__Voxelengine__GameScene__) */
