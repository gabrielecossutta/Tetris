//clang.exe -o Tetris.exe Tetris.c CheckCollision.c Audio.c Inputs.c DrawInterface.c -l raylibdll -I include

#include "Tetris.h"


int stage[] = // rappresentation of the stage
{
    1,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,1,1,1,1,
};
//block representation, some blocks do not require all rotation
const int lTetromino0[] = 
{
    0,1,0,0,
    0,1,0,0,
    0,1,1,0,
    0,0,0,0,
};

const int lTetromino90[] =
{
    0,0,0,0,
    1,1,1,0,
    1,0,0,0,
    0,0,0,0,
};

const int lTetromino180[] =
{
    1,1,0,0,
    0,1,0,0,
    0,1,0,0,
    0,0,0,0,
};

const int lTetromino270[] =
{
    0,0,1,0,
    1,1,1,0,
    0,0,0,0,
    0,0,0,0,
};

const int jTetromino0[] =
{
    0,1,0,0,
    0,1,0,0,
    1,1,0,0,
    0,0,0,0,
};

const int jTetromino90[] =
 {
    1,0,0,0,
    1,1,1,0,
    0,0,0,0,
    0,0,0,0,
};

const int jTetromino180[] =
{
    0,1,1,0,
    0,1,0,0,
    0,1,0,0,
    0,0,0,0,
};

const int jTetromino270[] =
{
    0,0,0,0,
    1,1,1,0,
    0,0,1,0,
    0,0,0,0,
};

const int oTetromino[] =
{
    1,1,0,0,
    1,1,0,0,
    0,0,0,0,
    0,0,0,0,
};

const int sTetromino0[] =
{
    0,0,0,0,
    0,1,1,0,
    1,1,0,0,
    0,0,0,0,
};

const int sTetromino90[] =
{
    1,0,0,0,
    1,1,0,0,
    0,1,0,0,
    0,0,0,0,
};

const int tTetromino0[] =
{
    0,0,0,0,
    1,1,1,0,
    0,1,0,0,
    0,0,0,0,
};

const int tTetromino90[] =
{
    0,1,0,0,
    1,1,0,0,
    0,1,0,0,
    0,0,0,0,
};

const int tTetromino180[] =
{
    0,1,0,0,
    1,1,1,0,
    0,0,0,0,
    0,0,0,0,
};

const int tTetromino270[] =
{
    0,1,0,0,
    0,1,1,0,
    0,1,0,0,
    0,0,0,0,
};

const int iTetromino0[] =
{
    0,1,0,0,
    0,1,0,0,
    0,1,0,0,
    0,1,0,0,
};

const int iTetromino90[] =
{
    0,0,0,0,
    1,1,1,1,
    0,0,0,0,
    0,0,0,0,
};

const int zTetromino0[] =
{
    0,0,0,0,
    1,1,0,0,
    0,1,1,0,
    0,0,0,0,
};

const int zTetromino90[] =
{
    0,1,0,0,
    1,1,0,0,
    1,0,0,0,
    0,0,0,0,
};
const Color colorTypes[8] =
{
    {255, 0, 0, 255}, //red
    {0, 255, 0, 255}, //green
    {128, 0, 128, 255}, //purple
    {255, 255, 0, 255}, //yellow
    {0, 255, 255, 255}, //cyan
    {0, 0, 255, 255}, //blue
    {255, 127, 0, 255}, //orange
    {127, 127, 127, 255}, // grey
};


const int *tetrominoTypes[7][4] = //array with all the tetromini and rotation
{
    {zTetromino0, zTetromino90, zTetromino0, zTetromino90},
    {sTetromino0, sTetromino90, sTetromino0, sTetromino90},
    {tTetromino0, tTetromino90, tTetromino180, tTetromino270},
    {oTetromino, oTetromino, oTetromino, oTetromino},
    {iTetromino0, iTetromino90, iTetromino0, iTetromino90},
    {jTetromino0, jTetromino90, jTetromino180, jTetromino270},
    {lTetromino0, lTetromino90, lTetromino180, lTetromino270},
};

//draw the tetromino
void DrawTetromino(const Color currentColor, const int startOffsetX, const int startOffsetY, const int tetrominoStartX, const int tetrominoStartY, const int *tetromino)
{
    for (int y = 0; y < TETROMINO_SIZE; y++)
    {
        for (int x = 0; x < TETROMINO_SIZE; x++)
        {
            const int offset = y * TETROMINO_SIZE + x;

            if (tetromino[offset] == 1)
            {
                DrawRectangle((x + tetrominoStartX) * TILE_SIZE + startOffsetX, (y + tetrominoStartY) * TILE_SIZE + startOffsetY, TILE_SIZE, TILE_SIZE, currentColor);
            }
        }
    }
}
//draw the next tetromino
void DrawNextTetromino(const Color currentColor, const int tetrominoStartX, const int tetrominoStartY, const int *tetromino)
{
    for (int y = 0; y < TETROMINO_SIZE; y++)
    {
        for (int x = 0; x < TETROMINO_SIZE; x++)
        {
            const int offset = y * TETROMINO_SIZE + x;

            if (tetromino[offset] == 1)
            {
                DrawRectangle((x + tetrominoStartX) * TILE_SIZE, (y + tetrominoStartY) * TILE_SIZE, TILE_SIZE, TILE_SIZE, currentColor);
            }
        }
    }
}

//draw the stage
void DrawBackgrond(const int startOffsetX,const  int startOffsetY)
{
    for (int y = 0; y < STAGE_HEIGHT; y++)
    {
        for (int x = 0; x < STAGE_WIDTH; x++)
        {
            const int offset = y * STAGE_WIDTH + x;
            const int color = stage[offset];
            if (stage[offset] != 0) // if the stage[] value is 1 we draw a grey square, to form the tetris arena, otherwise we draw a black square
            {
                DrawRectangle(x * TILE_SIZE + startOffsetX, y * TILE_SIZE + startOffsetY, TILE_SIZE, TILE_SIZE, colorTypes[BACKGROUNDCOLOR]);
            }

            DrawRectangleLines(x * TILE_SIZE + startOffsetX, y * TILE_SIZE + startOffsetY, TILE_SIZE, TILE_SIZE, BLACK);
        }
    }
}


void ResetLines(const int startLineY) // when we clear a line, we need to lower the other blocks
{
    for (int y = startLineY; y >= 0; y--)
    {
        for (int x = 1; x < STAGE_WIDTH - 1; x++)
        {
            const int offset = y * STAGE_WIDTH + x; // current block
            const int offset_below = (y + 1) * STAGE_WIDTH + x; // block below the current block
            if (stage[offset_below] == 0 && stage[offset] > 0)//if the block under the current block is empty we lower the block
            {
                stage[offset_below] = stage[offset];
                stage[offset] = 0;
            }
        }
    }
}

void DeleteLines(const Sound sound, float *score, int *lines, float *timer)//when we delete a line, we have to delete it
{
    float scoreMultiplier = 1; // used to mulpitly the score when we clear more line in one
    for (int y = 0; y < STAGE_HEIGHT - 1; y++)
    {
        int checkLine = 1; // used to see if we have a entire line of 1
        for (int x = 1; x < STAGE_WIDTH - 1; x++)
        {
            const int offset = y * STAGE_WIDTH + x;
            if (stage[offset] == 0) 
            {
                checkLine = 0;
                break;
            }
        }
        if (checkLine)//when we find a line of ones we update the score, we increase the velocity of the tetromino
        {
            const int offset = y * STAGE_WIDTH + 1;
            memset(stage + offset, 0, (STAGE_WIDTH - 2) * sizeof(int));//we convert all the ones in zeros
            DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(RED, 0.75f)); // we create a visual effect to see that we clear a line
            PlaySound(sound); // we play the clear effect
            ResetLines(y);//we lower the other blocks
            *lines += 1; // we add 1 for all deleted lines
            *timer -= 0.02; // we increase the velocity of the tetrominor 
            scoreMultiplier += 0.1; // we increate the score multiplier
            *score += 10 * scoreMultiplier; // we calculate the score
        }
    }
}

int CheckCollisionAtSpawn(const int tetrominoStartX, const int tetrominoStartY, const int tetrominoType,const int rotation) // check for collision when we create a new tetromino, return 1 if we have collision otherwise return 0
{
    const int *tetromino = tetrominoTypes[tetrominoType][rotation]; // we get the pointer of the new tetromino

    for (int y = 0; y < TETROMINO_SIZE; y++) //we scroll through the matrix
    {
        for (int x = 0; x < TETROMINO_SIZE; x++)
        {
            const int offset = y * TETROMINO_SIZE + x;

            if (tetromino[offset] == 1) //when we find 1 we check if the is another 1 in the stage at the same position
            {
                const int offsetX = x + tetrominoStartX;
                const int offsetY = y + tetrominoStartY;

                if (stage[offsetY * STAGE_WIDTH + offsetX] != 0)
                {
                    return 1; // if we have a collision we return a 1, that mean it's game over
                }
            }
        }
    }
    return 0; 
}

void ClearStage() // clean the stage
{
    for (int y = 0; y < STAGE_HEIGHT; y++)
    {
        for (int x = 0; x < STAGE_WIDTH; x++)
        {
            const int offset = y * STAGE_WIDTH + x;
            if (x == 0 || x == STAGE_WIDTH - 1 || y == STAGE_HEIGHT - 1)
                stage[offset] = 1;
            else
                stage[offset] = 0;
        }
    }
}


int main(int argc, char **argv, char **environ)
{
    Sound soundEffect; //clear sound
    Sound gameOverEffect; //gameover sound
    Music music; //music
    InitAudio(&soundEffect, &music, &gameOverEffect); 
    int lines = 0; //lines cleaned
    bool gameOver = false; //become true when the player lose
    float score = 0; //player score
    const int windowWidth = 800; //window width
    const int windowHeight = 700; //window height
    const int startOffsetX = (windowWidth / 2) - ((STAGE_WIDTH * TILE_SIZE) / 2) - 150; // starting point for drawing the arena
    const int startOffsetY = (windowHeight / 2) - ((STAGE_HEIGHT * TILE_SIZE) / 2);
    const int tetrominoStartX = STAGE_WIDTH / 2 - 1; //tetromino X spawning point 
    const int tetrominoStartY = 0; //tetromino Y spawning point 
    bool CheckCleanLine; // true if we drop a tetromino and we need to check if we have completed a line
    int currentTetrominoX = tetrominoStartX;
    int currentTetrominoY = tetrominoStartY;

    time_t unixTime; // number of second since 00:00, Jan 1 1970
    time(&unixTime); 
    SetRandomSeed(unixTime); //set the seed for the number generator

    int currentTetrominoType = GetRandomValue(0, 6); //generate aa tetromino
    int futureTetrominoType = GetRandomValue(0, 6); // generate the future tetromino
    int currentRotation = 0; //rotation of the tetromino

    float moveTetrominoDownTimer = 1.f; //when this timer turn to 0 the tetromino move down
    float timeToMoveTetrominoDown = moveTetrominoDownTimer;

    InitWindow(windowWidth, windowHeight, "TETRIS"); //used  for create the the window

    SetTargetFPS(60); //FPS target
    PlayMusicStream(music); //start the music
    SetMusicVolume(music, 0.25); //set the volume
    while (!WindowShouldClose())
    {
        if (!gameOver) //if the player lose he can't do anything
        {
            timeToMoveTetrominoDown -= GetFrameTime(); // subtract the frame from the timer
            CheckCleanLine = false;
            //player controls
            CheckCleanLine = Inputs(&currentRotation,&currentTetrominoX,&currentTetrominoY,currentTetrominoType,&timeToMoveTetrominoDown,moveTetrominoDownTimer,tetrominoTypes);
            if(CheckCleanLine)
            {
                DeleteLines(soundEffect, &score, &lines, &moveTetrominoDownTimer); //check if we have completed a line
                //we create a new tetromino
                currentTetrominoX = tetrominoStartX;
                currentTetrominoY = tetrominoStartY;
                currentTetrominoType = futureTetrominoType; 
                futureTetrominoType = GetRandomValue(0, 6); // set a new future tetromino
                currentRotation = 0;
                CheckCleanLine=false;
            }
        }
        BeginDrawing();
        if (CheckCollisionAtSpawn(tetrominoStartX, tetrominoStartY, currentTetrominoType, currentRotation))//check if we have a collision at the start, if we have a collision the player lose
        {

            if (!gameOver) // used for play the gameover effect a single time
            {
                gameOver = true;
                StopMusicStream(music);
                PlaySound(gameOverEffect);
            }

            DrawGameover(score);

            if (IsKeyPressed(KEY_R))//if the player press r the game restart
            {
                lines = 0;
                score = 0;
                moveTetrominoDownTimer = 1.f;
                timeToMoveTetrominoDown = moveTetrominoDownTimer;

                gameOver = false;
                ClearStage();
                PlayMusicStream(music);
            }
        }
        else
        {
            //draw the game
            ClearBackground(BLACK);
            DrawBackgrond(startOffsetX, startOffsetY);
            DrawTetromino(colorTypes[currentTetrominoType], startOffsetX, startOffsetY, currentTetrominoX, currentTetrominoY, tetrominoTypes[currentTetrominoType][currentRotation]);
            DrawNextTetromino(colorTypes[futureTetrominoType], FUTUREBLOCKX, FUTUREBLOCKY, tetrominoTypes[futureTetrominoType][0]);
            DrawHUD(score, lines, moveTetrominoDownTimer);
        }
        UpdateMusicStream(music);
        EndDrawing();
    }
    return 0;
}
