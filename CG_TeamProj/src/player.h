#pragma once
#include "object.h"
#include "stdafx.h"
class Player : public Object
{
protected:
    
    bool isMoveLeft = false;
    bool isMoveRight = false;
public:
    
    Player();
    void render(GLuint shaderProgramID) override;
    void colorInit();

    void update() override;
    void getEvent(unsigned char key, bool isDown);
    void setMoveLeft(bool);
    void setMoveRight(bool);
    void move();
};