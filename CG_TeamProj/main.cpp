#pragma once

#include "src/stdafx.h"
#include "src/shaders.h"

#include "src/camera.h"
#include "src/object.h"
#include "src/light.h"
#include "src/player.h"
#include "src/gameWorld.h"

GLvoid drawScene(GLvoid);
GLvoid Reshape(int w, int h);
GLvoid keyboard(unsigned char key, int x, int y);
GLvoid keyUp(unsigned char, int, int);

GLclampf g_color[4] = {0.5, 0.5, 0.5, 1.0f};
GLint width = 1200, height = 800;

GLuint shaderID;



Light light;
Camera camera;
Player player;

GameWorld gameWorld;

///////////////////////////////////////////

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
    
    player.initBuffer();
    player.colorInit();
    Object* playerPtr = &player;
    cout << 1 << endl;
    gameWorld.set_shader(shaderID);
    gameWorld.add_object(playerPtr);
    updateTimer(0);

    glutKeyboardFunc(keyboard);
    glutDisplayFunc(drawScene);
    glutReshapeFunc(Reshape);
    glutKeyboardUpFunc(keyUp);
    glutMainLoop();
    
}

GLvoid drawScene()
{
    glClearColor(g_color[0], g_color[1], g_color[2], g_color[3]);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glUseProgram(shaderID);

    camera.setCamera(shaderID, 0); // 0 = 원근투영 / 1 = 직각투영
    light.setLight(shaderID, camera.getEye());
    gameWorld.draw_all();
    player.render(shaderID);
    glutSwapBuffers();
}

GLvoid Reshape(int w, int h)
{
    glViewport(0, 0, 800, 800);
}

GLvoid keyboard(unsigned char key, int x, int y)
{
    player.getEvent(key, true);
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
GLvoid keyUp(unsigned char key, int x, int y)
{
    player.getEvent(key, false);
    glutPostRedisplay();

}

GLvoid updateTimer(int value)
{
    gameWorld.update_all();
    light.update();  // 공전
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, updateTimer, 0);
}