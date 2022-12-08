#pragma once
#include "soundManager.h"

SoundManager::SoundManager()
{
    FMOD::System_Create(&soundSystem);
    soundSystem->init(32, FMOD_INIT_NORMAL, 0);

    // soundSystem->createSound("res/bgm.wav", FMOD_LOOP_NORMAL, 0, &sound[BGM]);
    soundSystem->createSound("res/botton_click.wav", FMOD_DEFAULT, 0, &sound[BUTTON_CLICK]);
    soundSystem->createSound("res/player_destroy.wav", FMOD_DEFAULT, 0, &sound[PLAYER_DESTROY]);
    soundSystem->createSound("res/wall_destroy.wav", FMOD_DEFAULT, 0, &sound[WALL_DESTROY]);
    soundSystem->createSound("res/item_get.wav", FMOD_DEFAULT, 0, &sound[ITEM_DESTROY]);
}

void SoundManager::soundPlay(int _type)
{
    soundSystem->playSound(sound[_type], 0, false, &channel);
}
