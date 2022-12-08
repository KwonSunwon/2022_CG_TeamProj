#include "src/stdafx.h"
#include "src/shaders.h"

#include "src/camera.h"
#include "src/object.h"
#include "src/light.h"
#include "src/player.h"
#include "src/gameWorld.h"
#include "src/wall.h"
#include "src/gameManager.h"

GLvoid drawScene(GLvoid);
GLvoid Reshape(int w, int h);
GLvoid keyboard(unsigned char key, int x, int y);
GLvoid keyUp(unsigned char, int, int);
GLvoid Mouse(int, int, int, int);

GLclampf g_color[4] = {0.5, 0.5, 0.5, 1.0f};
GLint g_width = 1000, g_height = 1000;

GLuint shaderID;

extern Light light;
extern Camera camera;
extern GameManager gameManager;
extern GameWorld gameWorld;
extern int gameSpeed;

///////////////////////////////////////////

GLvoid updateTimer(int value);

// sound test
FMOD::System *soundSystem;
FMOD::Sound *sound;
FMOD::Channel *channel;

bool soundFlag = false;

void main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(300, 0);
    glutInitWindowSize(g_width, g_height);
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

    gameManager.gameRun();
    gameWorld.set_shader(shaderID);

    // sound test
    FMOD::System_Create(&soundSystem);
    soundSystem->init(32, FMOD_INIT_NORMAL, 0);
    soundSystem->createSound("res/sound_test2.wav", FMOD_DEFAULT, 0, &sound);

    updateTimer(0);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(drawScene);
    glutReshapeFunc(Reshape);
    glutKeyboardUpFunc(keyUp);
    glutMouseFunc(Mouse);
    glutMainLoop();
}

GLvoid drawScene()
{
    glClearColor(g_color[0], g_color[1], g_color[2], g_color[3]);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glUseProgram(shaderID);

    gameManager.draw();

    glutSwapBuffers();
}

GLvoid Reshape(int w, int h)
{
    glViewport(0, 0, 1000, 1000);
}

GLvoid keyboard(unsigned char key, int x, int y)
{
    gameManager.handleEvent(key, true);
    glutPostRedisplay();
}
GLvoid keyUp(unsigned char key, int x, int y)
{
    gameManager.handleEvent(key, false);
    glutPostRedisplay();
}
GLvoid Mouse(int button, int state, int x, int y)
{
    gameManager.handleEvent(button, state, x, y);
    glutPostRedisplay();
}
GLvoid updateTimer(int value)
{
    if (!soundFlag)
    {
        soundSystem->playSound(sound, 0, false, &channel);
        soundFlag = true;
    }

    gameManager.update();
    glutTimerFunc(1000 / gameSpeed, updateTimer, 0);
}