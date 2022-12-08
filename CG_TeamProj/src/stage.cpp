#pragma once
#include "stage.h"
#include "wall.h"
#include "gameWorld.h"
Wall* tempwall;
extern GameWorld gameWorld;

std::random_device rd4;
std::mt19937 gen4(rd4());
std::uniform_int_distribution<int> dis4(0, 360);

void Stage::makePattern(int patternNum)
{
    tempwall = new Wall(0,0);
    tempwall->initTexture();
    switch (patternNum)
    {
    case 0:
        cout << "make pattern case:0" << patternNum << endl;
        for (int i = 0; i < 9; ++i)
        {

            tempwall = new Wall(2.0f, 40.0f * i);
            tempwall->initBuffer();
            gameWorld.add_object(tempwall);

            tempwall = new Wall(4.0f, 40.0f * i + 15.0f);
            tempwall->initBuffer();
            gameWorld.add_object(tempwall);
        }
        break;

    case 1:
        cout << "make pattern case:1" << patternNum << endl;
        for (int i = 0; i < 24; ++i)
        {

            tempwall = new Wall(2.0f + (float)i * 0.3, 15.0f * (i % 24));
            tempwall->initBuffer();
            gameWorld.add_object(tempwall);
        }
        break;


    case 2:
        cout << "make pattern case:2"<<patternNum << endl;
        for (int i = 0; i < 24; ++i)
        {
            
            tempwall = new Wall(2.0f + (float)i * 0.3, 15.0f * (i%24));
            tempwall->initBuffer();
            gameWorld.add_object(tempwall);

            tempwall = new Wall(2.0f + (float)i * 0.3, 15.0f * ((i+12) % 24));
            tempwall->initBuffer();
            gameWorld.add_object(tempwall);
        }
        break;

    case 3:
        cout << "make pattern case:3" << patternNum << endl;
        for (int i = 0; i < 24; ++i)
        {

            tempwall = new Wall(2.0f + (float)i * 0.3, (float)dis4(gen4));
            tempwall->initBuffer();
            gameWorld.add_object(tempwall);
        }
        break;

    case 4:
        cout << "make pattern case:4" << patternNum << endl;
        for (int i = 0; i < 12; ++i)
        {

            tempwall = new Wall(2.0f + (float)i * 0.3, 15.0f * (i % 24));
            tempwall->initBuffer();
            gameWorld.add_object(tempwall);

            tempwall = new Wall(2.0f + (float)i * 0.3, 15.0f * ((i + 12) % 24));
            tempwall->initBuffer();
            gameWorld.add_object(tempwall);
        }

        for (int i = 12; i < 24; ++i)
        {

            tempwall = new Wall(2.0f + (float)i * 0.3, 15.0f * ((24-i) % 24));
            tempwall->initBuffer();
            gameWorld.add_object(tempwall);

            tempwall = new Wall(2.0f + (float)i * 0.3, 15.0f * ((36-i) % 24));
            tempwall->initBuffer();
            gameWorld.add_object(tempwall);
        }
        break;

    
    }
}