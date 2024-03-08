#include "raylib.h"
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#define STAGE_WIDTH 12
#define STAGE_HEIGHT 22
#define TILE_SIZE 24
#define TETROMINO_SIZE 4
#define BACKGROUNDCOLOR 7
#define HUDPOSITION 150 
#define FUTUREBLOCKX 24 
#define FUTUREBLOCKY 16
int CheckCollision(const int tetrominoStartX, const int tetrominoStartY, const int *tetromino);
void InitAudio(Sound *soundEffect, Music *music, Sound *gameOverEffect);
bool Inputs(int* currentRotation, int* currentTetrominoX, int* currentTetrominoY, const int currentTetrominoType, float* timeToMoveTetrominoDown, const float moveTetrominoDownTimer ,const int* tetrominoTypes[][4]);
void DrawHUD(const int score, const int lines, const float moveTetrominoDownTimer);
void DrawGameover(const int score);
