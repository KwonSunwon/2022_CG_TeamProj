#pragma once
#include "stage.h"
#include "stdafx.h"
class MainStage : public Stage
{
protected:

    
public:

    void init();
    void update();
    void handleEvent(unsigned char, bool) override;
};