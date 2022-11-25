#ifndef __WALL_H__
#define __WALL_H__

#include "object.h"
#include "stdafx.h"

class Wall : public Object
{
private:
    static GLint object;
    static vector<glm::vec3> vertices;
    static vector<glm::vec3> normals;

protected:
public:
    Wall();
    void render(GLuint shaderProgramID) override;
    void colorInit();
    void initBuffer() override;

    void update() override;
    void move();
};

#endif