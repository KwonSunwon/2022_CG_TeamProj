#include "player.h"

GLint Player::object = -1;
vector<glm::vec3> Player::vertices;
vector<glm::vec3> Player::normals;

Player::Player()
{
    if (object == -1)
    {
        object = objReader.loadObj("res/sphere.obj");
        vertices.resize(objReader.out_vertices.size());
        normals.resize(objReader.out_normals.size());
        for (int i = 0; i < objReader.out_vertices.size(); i++)
        {
            vertices[i] = objReader.out_vertices[i];
        }
        for (int i = 0; i < objReader.out_normals.size(); i++)
        {
            normals[i] = objReader.out_normals[i];
        }
    }
    setPosY(-1.0f);
}

void Player::initBuffer()
{
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &nbo);

    // vertices
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    // normals
    glBindBuffer(GL_ARRAY_BUFFER, nbo);
    glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), &normals[0], GL_STATIC_DRAW);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(1);
}

void Player::render(GLuint shaderProgramID)
{
    glUseProgram(shaderProgramID);

    model = glm::mat4(1.0);
    model = glm::rotate(model, glm::radians(revolution.z), glm::vec3(0, 0, 1));
    model = glm::translate(model, pos);
    model = glm::rotate(model, glm::radians(rotate.y), glm::vec3(0, 1, 0));
    model = glm::scale(model, glm::vec3(0.1, 0.1, 0.1));

    glUniformMatrix4fv(glGetUniformLocation(shaderProgramID, "model"), 1, GL_FALSE, glm::value_ptr(model));

    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, Player::object);
}

void Player::colorInit()
{
    for (int i = 0; i < Player::vertices.size(); i++)
    {
        colors.push_back(0.0f);
        colors.push_back(1.0f);
        colors.push_back(0.7f);
    }

    glGenBuffers(1, &cbo);
    glBindBuffer(GL_ARRAY_BUFFER, cbo);
    glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(float), &colors[0], GL_STATIC_DRAW);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
    glEnableVertexAttribArray(2);
}

void Player::update()
{
    rotate.y += 0.1;
    move();
}

void Player::getEvent(unsigned char key, bool isDown)
{
}
void Player::setMoveLeft(bool in) { isMoveLeft = in; }
void Player::setMoveRight(bool in) { isMoveRight = in; }
void Player::move()
{

    if (isMoveLeft)
        setRevolutionZ(revolution.z - 1.0f);
    if (isMoveRight)
        setRevolutionZ(revolution.z + 1.0f);
}