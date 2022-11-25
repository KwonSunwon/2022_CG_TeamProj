#pragma once
#include "gameWorld.h"
#include "light.h"
#include "camera.h"
#include "wall.h"
#include "player.h"
#include "gameManager.h"
#include "object.h"
#include "stage.h"
#include <vector>

GameWorld gameWorld;
Light light;
Camera camera;
Player player;
// Wall wall;
// Wall *wallPtr;
GameManager gameManager;
Object *playerPtr = &player;
int nowStage = 0;
vector<Stage *> stages;