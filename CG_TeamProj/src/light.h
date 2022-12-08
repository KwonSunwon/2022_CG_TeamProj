#ifndef __LIGHT_H__
#define __LIGHT_H__

#include "object.h"

class Light : public Object
{
private:
    float ambientLight;
    int shininess;
    float angle;

public:
    Light();

    void setLight(GLuint shaderProgramID, glm::vec3 viewPos);
    void update() override;

    void setAmbientLight(float ambientLight);
};

#endif