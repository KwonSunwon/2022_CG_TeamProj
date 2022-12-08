#pragma once
#include "soundManager.h"

SoundManager::SoundManager()
{
    FMOD::System_Create(&soundSystem);
    soundSystem->init(32, FMOD_INIT_NORMAL, 0);

    soundSystem->createSound("res/sound_test2.wav", FMOD_DEFAULT, 0, &sound[0]);
    soundSystem->createSound("res/sound_test2.wav", FMOD_DEFAULT, 0, &sound[1]);
    soundSystem->createSound("res/sound_test2.wav", FMOD_DEFAULT, 0, &sound[2]);
    soundSystem->createSound("res/sound_test2.wav", FMOD_DEFAULT, 0, &sound[3]);
    soundSystem->createSound("res/sound_test2.wav", FMOD_DEFAULT, 0, &sound[4]);
}

void SoundManager::soundPlay(int num)
{
    soundSystem->playSound(sound[num], 0, false, &channel);
}


