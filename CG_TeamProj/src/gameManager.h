#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include "object.h"
#include "stdafx.h"

class GameManager
{
private:
    int gameMode = 0;

public:
    GameManager();
    void gameRun();
    void handleEvent(unsigned char, bool);
    void update();
    void draw();
};

#endif