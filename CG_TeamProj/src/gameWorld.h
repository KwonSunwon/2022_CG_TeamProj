#pragma once
#include "object.h"
#include "stdafx.h"

class GameWorld
{
private:
    vector<Object*> objects;
    GLuint shaderProgramID;

public:
    GameWorld();
    void draw_all();
    void update_all();
    void add_object(Object*);
    void set_shader(GLuint);
};