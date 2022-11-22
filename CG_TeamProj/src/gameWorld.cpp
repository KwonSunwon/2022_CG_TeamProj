#pragma once
#include "gameWorld.h"
GameWorld::GameWorld()
{
}

void GameWorld::set_shader(GLuint shaderProgramID)
{
	this->shaderProgramID = shaderProgramID;
}

void GameWorld::draw_all()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		objects[i]->render(shaderProgramID);
	}
	
}

void GameWorld::add_object(Object* o)
{
	objects.push_back(o);
}

void GameWorld::update_all()
{
	for (int i = 0; i < objects.size(); ++i)
	{
		objects[i]->update();
	}
}
