#pragma once
#include "startStage.h"
#include "player.h"
#include "light.h"
#include "gameWorld.h"
#include "camera.h"
#include "wall.h"
#include "easyStage.h"
#include "normalStage.h"
#include "hardStage.h"

extern Player player;
extern Light light;
extern GameWorld gameWorld;
extern Camera camera;
extern GLuint shaderID;
extern Object* playerPtr;
extern vector<Stage*> stages;
extern int nowStage;


EasyStage* easyStage = new EasyStage();
NormalStage* normalStage = new NormalStage();
HardStage* hardStage = new HardStage();


//2dgp�� enter
void StartStage::init()
{
    cout << "StartStage" << endl;
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
        case'1':
            stages.back()->out();
            nowStage++;
            stages.push_back(easyStage);
            stages[nowStage]->init();
            break;
        case'2':
            stages.back()->out();
            nowStage++;
            stages.push_back(normalStage);
            stages[nowStage]->init();
            break;
        case'3':
            stages.back()->out();
            nowStage++;
            stages.push_back(hardStage);
            stages[nowStage]->init();
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