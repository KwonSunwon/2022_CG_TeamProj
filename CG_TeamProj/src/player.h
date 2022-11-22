#include "object.h"
#include "stdafx.h"
class Player : public Object
{
public:
    Player();
    void render(GLuint shaderProgramID) override;
    void colorInit();

    void update() override;
};