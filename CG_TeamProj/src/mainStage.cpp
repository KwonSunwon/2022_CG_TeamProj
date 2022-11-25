#pragma once
#include "mainStage.h"
#include "player.h"

extern Player player;

void MainStage::init() 
{

}
void MainStage::update() 
{

}
void MainStage::handleEvent(unsigned char key, bool isDown) 
{
    cout << "here" << endl;
    if (isDown)
    {
        switch (key)
        {

        case 'a':
            player.setMoveLeft(true);
            break;
        case 'd':
            player.setMoveRight(true);
            break;
        }
    }
    else if (!isDown)
    {
        switch (key)
        {

        case 'a':
            player.setMoveLeft(false);
            break;
        case 'd':
            player.setMoveRight(false);
            break;
        }
    }
}