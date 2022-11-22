#pragma once

#include "stdafx.h"
#include "objReader.h"

using namespace std;

typedef class Object
{
protected:
    glm::vec3 pos;
    glm::vec3 scale;
    glm::vec3 rotate;
    glm::vec3 revolution;

    GLuint vao;
    GLuint vbo;
    GLuint nbo;
    GLuint cbo;
    GLuint ebo;

    glm::mat4 model;

    vector<float> vertices;
    vector<float> colors;
    vector<GLubyte> indices;

    objRead objReader;
    GLint object;

public:
    Object();

    // Not using an Obj file
    Object(vector<float> vertices, vector<float> colors);
    Object(vector<float> vertices, vector<float> colors, vector<GLubyte> indices);

    // Using an Obj file
    Object(const char *fileName);

    virtual void init();
    void initPos();
    virtual void initBuffer();
    virtual void _initBuffer();

    void setModelPos(vector<float> vertices);
    void setModelColor(vector<float> colors);
    void setModelIndices(vector<GLubyte> indices);

    void initModel(vector<float> vertices, vector<float> colors);
    void initModel(vector<float> vertices, vector<float> colors, vector<GLubyte> indices);

    virtual void render(GLuint shaderProgramID){};
    virtual void update(){};

    // Setters
    void setPos(glm::vec3 pos);
    void setPosX(float x);
    void setPosY(float y);
    void setPosZ(float z);

    void setScale(glm::vec3 scale);
    void setScaleX(float x);
    void setScaleY(float y);
    void setScaleZ(float z);

    void setRotate(glm::vec3 rotate);
    void setRotateX(float x);
    void setRotateY(float y);
    void setRotateZ(float z);

    void setRevolution(glm::vec3 revolution);
    void setRevolutionX(float x);
    void setRevolutionY(float y);
    void setRevolutionZ(float z);

    // Getters
    glm::vec3 getPos();
    glm::vec3 getScale();
    glm::vec3 getRotate();

} Object;