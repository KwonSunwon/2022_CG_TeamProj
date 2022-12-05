#ifndef __STAGE_H__
#define __STAGE_H__

#include "stdafx.h"
using namespace std;

typedef class Stage
{
protected:
    int timer = 0;
public:
    virtual void init(){};
    virtual void update(){};
    virtual void handleEvent(unsigned char, bool){};
    virtual void draw(){};
    virtual void out(){};
    void makePattern(int);
} Stage;

#endif