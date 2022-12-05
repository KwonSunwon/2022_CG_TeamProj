#pragma once
#include "easyStage.h"
#include "player.h"
#include "light.h"
#include "gameWorld.h"
#include "camera.h"
#include "wall.h"
#include "particle.h"
extern Player player;
extern Light light;
extern GameWorld gameWorld;
extern Camera camera;
extern GLuint shaderID;
extern Object *playerPtr;
extern Wall wall;

void EasyStage::init()
{
    cout << "easy Stage" << endl;
    player.initBuffer();
    player.initTexture();
    gameWorld.add_object(playerPtr);

    /*for (int i = 0; i < 100; ++i)
    {
        cout << i << endl;
        Wall *tempwall = new Wall();
        tempwall->initBuffer();
        tempwall->initTexture();
        gameWorld.add_object(tempwall);
    }*/
    makePattern(1);
    for (int i = 0; i < 20; ++i)
    {
        cout << i << endl;
        Particle *tempP = new Particle(true);
        tempP->initBuffer();
        gameWorld.add_object(tempP);
    }
}
void EasyStage::update()
{
    gameWorld.update_all();
    light.update(); // ����

    // Camera rolling test
    camera.rolling(0.5, -1); // angle, direction

    glutPostRedisplay();
}
void EasyStage::handleEvent(unsigned char key, bool isDown)
{
    if (isDown)
    {
        switch (key)
        {
        case'c':
            makePattern(1);
            //player.setProtectedMode(true);
            break;
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
void EasyStage::draw()
{
    camera.setCamera(shaderID, 0); // 0 = �������� / 1 = ��������
    light.setLight(shaderID, camera.getEye());
    gameWorld.draw_all();
}
void EasyStage::out()
{
}