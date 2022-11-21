#include "src/stdafx.h"
#include "src/shaders.h"

#include "src/camera.h"
#include "src/object.h"

GLvoid drawScene(GLvoid);
GLvoid Reshape(int w, int h);
GLvoid keyboard(unsigned char key, int x, int y);

GLclampf g_color[4] = {0.5, 0.5, 0.5, 1.0f};
GLint width = 1200, height = 800;

// shader variables
GLuint shaderID;

class Sphere : public Object
{
public:
    Sphere(const char *file);
    void render(GLuint shaderProgramID) override;
    void colorInit();

    void update() override;
};

Camera camera;
Sphere sphere("res/sphere.obj");

GLvoid updateTimer(int value);

void main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(width, height);
    glutCreateWindow("Last Project");
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        std::cerr << "Unable to initialize GLEW" << std::endl;
        exit(EXIT_FAILURE);
    }
    else
        std::cout << "GLEW Initialized" << std::endl;

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    shaderID = initShader("res/shader.vert", "res/shader.frag");

    sphere.initBuffer();
    sphere.colorInit();

    updateTimer(0);

    glutKeyboardFunc(keyboard);
    glutDisplayFunc(drawScene);
    glutReshapeFunc(Reshape);
    glutMainLoop();
}

GLvoid drawScene()
{
    glClearColor(g_color[0], g_color[1], g_color[2], g_color[3]);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glUseProgram(shaderID);

    camera.setCamera(shaderID, 0);
    sphere.render(shaderID);

    glutSwapBuffers();
}

GLvoid Reshape(int w, int h)
{
    glViewport(0, 0, 800, 800);
}

GLvoid keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {

    // Exit
    case 'Q':
    case 'q':
        exit(0);
        break;
    }
    glutPostRedisplay();
}

void Sphere::render(GLuint shaderProgramID)
{
    glUseProgram(shaderProgramID);

    // Set the model matrix
    model = glm::mat4(1.0);
    model = glm::translate(model, pos);
    model = glm::rotate(model, glm::radians(rotate.y), glm::vec3(0, 1, 0));

    glUniformMatrix4fv(glGetUniformLocation(shaderProgramID, "model"), 1, GL_FALSE, glm::value_ptr(model));

    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, object);
}

void Sphere::colorInit()
{
    for (int i = 0; i < objReader.out_vertices.size(); i++)
    {
        colors.push_back(0.0f);
        colors.push_back(0.7f);
        colors.push_back(0.7f);
    }

    glGenBuffers(1, &cbo);
    glBindBuffer(GL_ARRAY_BUFFER, cbo);
    glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(float), &colors[0], GL_STATIC_DRAW);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
    glEnableVertexAttribArray(1);
}

Sphere::Sphere(const char *file)
{
    object = objReader.loadObj(file);
}

void Sphere::update()
{
    rotate.y += 0.1;
}

GLvoid updateTimer(int value)
{
    sphere.update();
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, updateTimer, 0);
}