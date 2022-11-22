#pragma once
#include "object.h"
#include "stdafx.h"
class Wall : public Object
{
protected:

public:

    Wall();
    void render(GLuint shaderProgramID) override;
    void colorInit();

    void update() override;
    void move();
};