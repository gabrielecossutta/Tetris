#include "Tetris.h"

void InitAudio(Sound *soundEffect, Music *music, Sound *gameOverEffect) //initializes wav files
{
    InitAudioDevice();//initializes audio device
    *gameOverEffect = LoadSound("sound/GameOver.wav");
    *soundEffect = LoadSound("sound/lineClear.wav");
    *music = LoadMusicStream("sound/mainMusic.wav");
}