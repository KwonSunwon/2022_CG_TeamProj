#pragma once
#include "stage.h"
#include "stdafx.h"
class StartStage : public Stage
{
protected:


public:

    void init();
    void update();
    void handleEvent(unsigned char, bool);
    void draw();
    void out();
};