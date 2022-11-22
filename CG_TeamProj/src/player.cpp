#include "player.h"
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
    glDrawArrays(GL_TRIANGLES, 0, object);
}

void Player::colorInit()
{
    for (int i = 0; i < objReader.out_vertices.size(); i++)
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

Player::Player()
{
    object = objReader.loadObj("res/sphere.obj");
    setPosY(-1.0f);
}

void Player::update()
{
    rotate.y += 0.1;
    move();
}

void Player::getEvent(unsigned char key, bool isDown)
{
    if (isDown)
    {
        switch (key)
        {

        case 'a':
            setMoveLeft(true);
            break;
        case 'd':
            setMoveRight(true);
            break;
        }
    }
    else if (!isDown)
    {
        switch (key)
        {

        case 'a':
            setMoveLeft(false);
            break;
        case 'd':
            setMoveRight(false);
            break;
        }
    }
}
void Player::setMoveLeft(bool in) { isMoveLeft = in; }
void Player::setMoveRight(bool in) { isMoveRight = in; }
void Player::move()
{
    if (isMoveLeft) setRevolutionZ(revolution.z - 1.0f);
    if (isMoveRight)setRevolutionZ(revolution.z + 1.0f);
}