#pragma once
#include "mainStage.h"
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

//2dgp의 enter
void MainStage::init()
{
    //fill here

    //player.initBuffer();
    //player.colorInit();
    //gameWorld.add_object(playerPtr);

    //for (int i = 0; i < 2; ++i)
    //{
    //    cout << i << endl;
    //    Wall* tempwall = new Wall();
    //    //tempwall->initBuffer();
    //    //tempwall->colorInit();
    //    gameWorld.add_object(tempwall);
    //}
}

//2dgp의 update
void MainStage::update()
{
    //gameWorld.update_all();
    //light.update();  // 공전
    glutPostRedisplay();
}

//2dgp의 이벤트 핸들러
void MainStage::handleEvent(unsigned char key, bool isDown)
{
    if (isDown)
    {
        switch (key)
        {

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

        }
    }


}

//2dgp의 draw
void MainStage::draw()
{
    camera.setCamera(shaderID, 0); // 0 = 원근투영 / 1 = 직각투영
    light.setLight(shaderID, camera.getEye());
    gameWorld.draw_all();
}
void MainStage::out()
{}