#include "wall.h"
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dis(0, 360);


void Wall::render(GLuint shaderProgramID)
{
    glUseProgram(shaderProgramID);

    model = glm::mat4(1.0);
    model = glm::rotate(model, glm::radians(revolution.z), glm::vec3(0, 0, 1));
    model = glm::translate(model, pos);
    model = glm::rotate(model, glm::radians(rotate.y), glm::vec3(0, 1, 0));
    model = glm::scale(model, glm::vec3(0.1, 0.1, 0.1));

    glUniformMatrix4fv(glGetUniformLocation(shaderProgramID, "model"), 1, GL_FALSE, glm::value_ptr(model));

    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, object);
}

void Wall::colorInit()
{
    for (int i = 0; i < objReader.out_vertices.size(); i++)
    {
        colors.push_back(0.5f);
        colors.push_back(0.3f);
        colors.push_back(0.7f);
    }

    glGenBuffers(1, &cbo);
    glBindBuffer(GL_ARRAY_BUFFER, cbo);
    glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(float), &colors[0], GL_STATIC_DRAW);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
    glEnableVertexAttribArray(2);
}

Wall::Wall()
{
    object = objReader.loadObj("res/sphere.obj");
    setPosY(-1.0f);
    setPosZ(-5.0f);
    setRevolutionZ((float)dis(gen));
}

void Wall::update()
{
 
    move();
}

void Wall::move()
{
    setPosZ(pos.z + 0.03f);
}