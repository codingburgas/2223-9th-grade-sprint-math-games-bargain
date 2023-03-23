#include "raylib.h"
#include "Header.h"

void timer() 
{

   
    float time = 0.0f;
    float timeLeft = 0.0f;
    bool timerStarted = false;

    while (!WindowShouldClose()) {

        if (timerStarted) {
            float currentTime = (float)GetTime();
            timeLeft = 60.0f - (currentTime - time);

            if (timeLeft < 0.0f) {
                timeLeft = 0.0f;
                timerStarted = false;
                CloseWindow();
            }
        }


        BeginDrawing();
        ClearBackground(BLACK);
        if (timerStarted) 
        {
            DrawText(TextFormat("Time remaining: %.2f", timeLeft), 10, 10, 20, RAYWHITE);
        }
       
        EndDrawing();


        if (IsKeyPressed(KEY_SPACE)) {
            time = (float)GetTime();
            timerStarted = true;
        }

    }

    
    
}