#include "raylib.h"
#include "Header.h"

void countdown()
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    float time = 0.0f;
    float timeLeft = 0.0f;
    while (!WindowShouldClose()) {
            float currentTime = (float)GetTime();
            timeLeft = 6.5f - (currentTime - time);

            if (timeLeft < 0.0f) {
                timeLeft = 0.0f;
                game();
            }
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText(TextFormat("%.0f", timeLeft), 10, 10, 20, RAYWHITE);
        EndDrawing();
    }
}