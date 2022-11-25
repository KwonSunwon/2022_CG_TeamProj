#pragma once
#include "hardStage.h"
#include "player.h"
#include "light.h"
#include "gameWorld.h"
#include "camera.h"
#include "wall.h"
extern Player player;
extern Light light;
extern GameWorld gameWorld;
extern Camera camera;
extern GLuint shaderID;
extern Object* playerPtr;

void HardStage::init()
{
    cout << "hard Stage" << endl;
    player.initBuffer();
    player.colorInit();
    gameWorld.add_object(playerPtr);

    for (int i = 0; i < 1; ++i)
    {
        cout << i << endl;
        Wall* tempwall = new Wall();
        tempwall->initBuffer();
        //tempwall->colorInit();
        gameWorld.add_object(tempwall);
    }
}
void HardStage::update()
{
    gameWorld.update_all();
    light.update(); // ����
    glutPostRedisplay();
}
void HardStage::handleEvent(unsigned char key, bool isDown)
{
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
        case 'Q':
        case 'q':
            exit(0);
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
void HardStage::draw()
{
    camera.setCamera(shaderID, 0); // 0 = �������� / 1 = ��������
    light.setLight(shaderID, camera.getEye());
    gameWorld.draw_all();
}
void HardStage::out()
{
}