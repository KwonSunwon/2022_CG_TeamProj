#pragma once
#include "gameManager.h"
#include "player.h"
#include "gameWorld.h"
#include "wall.h"
#include "stage.h"
#include "mainStage.h"
#include <vector>
extern Player player;
extern GameWorld gameWorld;
extern Object* playerPtr;
extern vector<Stage*> stages;
extern int nowStage;
MainStage* mainStage = new MainStage();
GameManager::GameManager()
{
}

void GameManager::gameRun()
{
    stages.push_back(mainStage);
	cout << ("gameRun");
	player.initBuffer();
	player.colorInit();
	gameWorld.add_object(playerPtr);

    /*for (int i = 0; i < 2; ++i)
    {
        cout << i << endl;
        Wall* tempwall = new Wall();
        tempwall->initBuffer();
        tempwall->colorInit();
        gameWorld.add_object(tempwall);
    }*/
}

void GameManager::handleEvent(unsigned char key, bool isDown)
{
    
    stages[nowStage]->handleEvent(key, isDown);
}


