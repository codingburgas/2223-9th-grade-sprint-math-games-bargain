#include "raylib.h"
#include "Header.h"

void countdown()
{

    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Game");
    Texture2D background = LoadTexture("../assets/menu-bg.png");

    float time = 0.0f;
    float timeLeft = 0.0f;
    while (!WindowShouldClose()) {
        DrawTexture(background, 0, 0, WHITE);
        float currentTime = (float)GetTime();
            timeLeft = 5.5f - (currentTime - time);

            if (timeLeft < 0.0f) {
                timeLeft = 0.0f;
                game();
            }
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText(TextFormat("%.0f", timeLeft), screenWidth/2 - 30, screenHeight/2 - 40, 100, RAYWHITE);
        EndDrawing();
    }
}