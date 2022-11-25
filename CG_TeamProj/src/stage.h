#pragma once

#include "stdafx.h"
using namespace std;

typedef class Stage
{
protected:


public:
    virtual void init() {};
    virtual void update() {};
    virtual void handleEvent(unsigned char, bool) {};
} Stage;