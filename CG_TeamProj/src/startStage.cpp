#pragma once
#include "startStage.h"
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

//2dgp�� enter
void StartStage::init()
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

//2dgp�� update
void StartStage::update()
{
    //gameWorld.update_all();
    //light.update();  // ����
    glutPostRedisplay();
}

//2dgp�� �̺�Ʈ �ڵ鷯
void StartStage::handleEvent(unsigned char key, bool isDown)
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

//2dgp�� draw
void StartStage::draw()
{
    camera.setCamera(shaderID, 0); // 0 = �������� / 1 = ��������
    light.setLight(shaderID, camera.getEye());
    gameWorld.draw_all();
}

//2dgp�� 
void StartStage::out()
{}