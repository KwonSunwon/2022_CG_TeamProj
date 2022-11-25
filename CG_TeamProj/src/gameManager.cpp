#pragma once
#include "gameManager.h"
#include "player.h"
#include "gameWorld.h"
#include "wall.h"
#include "stage.h"
#include "mainStage.h"
#include <vector>
extern GameWorld gameWorld;
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
    stages[nowStage]->init();
}

void GameManager::handleEvent(unsigned char key, bool isDown)
{
    
    stages[nowStage]->handleEvent(key, isDown);
}

void GameManager::update()
{
    stages[nowStage]->update();
}
void GameManager::draw()
{
    stages[nowStage]->draw();
}


