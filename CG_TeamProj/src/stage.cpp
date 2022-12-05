#pragma once
#include "stage.h"
#include "wall.h"
#include "gameWorld.h"
Wall* tempwall;
extern GameWorld gameWorld;
void Stage::makePattern(int patternNum)
{
    
    switch (patternNum)
    {

    case 1:
        cout << "make pattern"<<patternNum << endl;
        for (int i = 0; i < 24; ++i)
        {
            
            tempwall = new Wall(2.0f + (float)i * 0.3, 15.0f * (i%24));
            if(i==0)
                tempwall->initTexture();
            tempwall->initBuffer();
            //tempwall->initTexture();

            gameWorld.add_object(tempwall);

            tempwall = new Wall(2.0f + (float)i * 0.3, 15.0f * ((i+12) % 24));

            tempwall->initBuffer();
            //tempwall->initTexture();

            gameWorld.add_object(tempwall);
        }
        break;
    }
}