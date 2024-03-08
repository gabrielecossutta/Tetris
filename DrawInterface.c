#include "Tetris.h"
void DrawHUD(const int score, const int lines, const float moveTetrominoDownTimer) // allows to draw the HUD 
{
    int level = 11 - moveTetrominoDownTimer * 10; // we calculate the level, the lower is the timer the more high is the level
    DrawText(TextFormat("LEVEL: %d", level), 445, HUDPOSITION - 55, 50, WHITE);
    DrawText(TextFormat("SCORE: %d", score), 445, HUDPOSITION, 50, WHITE);
    DrawText(TextFormat("LINES: %d", lines), 445, HUDPOSITION + 55, 50, WHITE);
    DrawText(TextFormat("NEXT BLOCK"), 445, HUDPOSITION + 110, 50, WHITE);
    DrawText(TextFormat(" ______\n\n ______"), 500, HUDPOSITION + 165, 50, WHITE);
    DrawText(TextFormat(" |        |"), 500, HUDPOSITION + 205, 50, WHITE);
    DrawText(TextFormat(" |        |"), 500, HUDPOSITION + 257, 50, WHITE);
    DrawText(TextFormat(" |        |"), 500, HUDPOSITION + 310, 50, WHITE);
}

void DrawGameover(const int score)//draw the gameover and show the final score
{
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, 1));
    DrawText("GAME OVER!", 265, 300, 50, RED);
    DrawText(TextFormat("SCORE: %d", score), 300, 350, 50, WHITE);
    DrawText("PRESS 'R' TO RESTART", 250, 400, 30, WHITE);
}