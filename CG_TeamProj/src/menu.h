#ifndef __MENU_H__
#define __MENU_H__

#include "object.h"

class Menu : public Object
{
private:
    vector<glm::vec3> vertices;
    vector<glm::vec3> normals;
    vector<glm::vec2> uvs;
    GLuint texture;

public:
    Menu();
    void render(GLuint shaderProgramID) override;
    void initBuffer() override;
    void initTexture() override;
    void update() override;

    void clicked(int x, int y);
};

#endif