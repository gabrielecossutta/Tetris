#include "Tetris.h"

// extern const int* tetrominoTypes[7][];
extern int stage[];


bool Inputs(int* currentRotation, int* currentTetrominoX, int* currentTetrominoY, const int currentTetrominoType, float* timeToMoveTetrominoDown, const float moveTetrominoDownTimer,const int* tetrominoTypes[][4])
{
    if (IsKeyPressed(KEY_SPACE)) // rotate the tetromino
    {
        const int lastRotation = (*currentRotation);
        (*currentRotation)++;
        if ((*currentRotation) > 3)
        {
            (*currentRotation) = 0;
        }
        if (CheckCollision((*currentTetrominoX), (*currentTetrominoY), tetrominoTypes[currentTetrominoType][(*currentRotation)]))
        {
            (*currentRotation) = lastRotation;
        }
    }
    if (IsKeyPressed(KEY_RIGHT)) // move tetromino rigth
    {
        if (!CheckCollision((*currentTetrominoX) + 1, (*currentTetrominoY), tetrominoTypes[currentTetrominoType][(*currentRotation)]))
        {
            (*currentTetrominoX)++;
        }
    }
    if (IsKeyPressed(KEY_LEFT)) // move tetromino left
    {
        if (!CheckCollision((*currentTetrominoX) - 1, (*currentTetrominoY), tetrominoTypes[currentTetrominoType][(*currentRotation)]))
        {
            (*currentTetrominoX)--;
        }
    }
    if (IsKeyPressed(KEY_UP)) // drop tetromino down
    {
        while (!CheckCollision((*currentTetrominoX), (*currentTetrominoY) + 1, tetrominoTypes[currentTetrominoType][(*currentRotation)]))
        {
            (*currentTetrominoY)++;
        }
        for (int y = 0; y < TETROMINO_SIZE; y++)
        {
            for (int x = 0; x < TETROMINO_SIZE; x++)
            {
                const int offset = y * TETROMINO_SIZE + x;

                const int *tetromino = tetrominoTypes[currentTetrominoType][(*currentRotation)];

                if (tetromino[offset] == 1)
                {
                    const int offset_stage = (y + (*currentTetrominoY)) * STAGE_WIDTH + (x + (*currentTetrominoX));
                    stage[offset_stage] = BACKGROUNDCOLOR;
                }
            }
        }
        
        return true;
    }
    if ((*timeToMoveTetrominoDown) <= 0 || IsKeyPressed(KEY_DOWN)) // move tetromino down
    {
        if (!CheckCollision((*currentTetrominoX), (*currentTetrominoY) + 1, tetrominoTypes[currentTetrominoType][(*currentRotation)]))
        {
            (*currentTetrominoY)++;
            (*timeToMoveTetrominoDown) = moveTetrominoDownTimer;
        }
        else
        {
            for (int y = 0; y < TETROMINO_SIZE; y++)
            {
                for (int x = 0; x < TETROMINO_SIZE; x++)
                {
                    const int offset = y * TETROMINO_SIZE + x;

                    const int *tetromino = tetrominoTypes[currentTetrominoType][(*currentRotation)];

                    if (tetromino[offset] == 1)
                    {
                        const int offset_stage = (y + (*currentTetrominoY)) * STAGE_WIDTH + (x + (*currentTetrominoX));
                        stage[offset_stage] = BACKGROUNDCOLOR;
                    }
                }
            }
            return true;
        }
    }
    return false;
}