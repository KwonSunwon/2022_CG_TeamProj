#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "object.h"
#include "stdafx.h"

class Player : public Object
{
private:
    static GLint object;
    static vector<glm::vec3> vertices;
    static vector<glm::vec3> normals;
    static vector<glm::vec2> uvs;

    static unsigned int texture;

protected:
    bool isMoveLeft = false;
    bool isMoveRight = false;

public:
    Player();
    void render(GLuint shaderProgramID) override;
    void colorInit();
    void initTexture() override;
    void initBuffer() override;

    void update() override;
    void getEvent(unsigned char key, bool isDown);
    void setMoveLeft(bool);
    void setMoveRight(bool);
    void move();
};

#endif
