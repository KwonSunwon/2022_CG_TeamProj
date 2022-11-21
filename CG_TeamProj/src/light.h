#pragma once
#include "object.h"

class Light : public Object
{
private:
    glm::vec3 ambientLight;
    int shininess;

    float angle;

public:
    Light();

    void setLight(GLuint shaderProgramID, glm::vec3 viewPos);
    void update() override;
};