#include "raylib.h"
#include "Header.h"

#define MAX_INPUT_CHARS 9

void game()
{
    const int screenWidth = 800;
    const int screenHeight = 450;


    // Load texture
    Image image = LoadImage("../assets/c4.png");
    ImageResize(&image, 200, 250);
    Texture2D texture = LoadTextureFromImage(image);
    UnloadImage(image);

    // Set up text box
    char name[MAX_INPUT_CHARS + 1] = "\0";
    int letterCount = 0;
    Rectangle textBox = { screenWidth / 2.0f - 100, 250, 225, 50 };

    // Timer
    float time = 0.0f;
    float timeLeft = 0.0f;
    bool timerStarted = false;

    while (!WindowShouldClose()) {

        // Handle text input
        bool mouseOnText = CheckCollisionPointRec(GetMousePosition(), textBox);
        if (mouseOnText) SetMouseCursor(MOUSE_CURSOR_IBEAM);
        else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

        int key = GetCharPressed();
        while (key > 0) {
            if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS)) {
                name[letterCount] = (char)key;
                name[letterCount + 1] = '\0';
                letterCount++;
            }
            key = GetCharPressed();
        }

        if (IsKeyPressed(KEY_BACKSPACE)) {
            letterCount--;
            if (letterCount < 0) letterCount = 0;
            name[letterCount] = '\0';
        }

        // Timer
        if (timerStarted) {
            float currentTime = (float)GetTime();
            timeLeft = 60.0f - (currentTime - time);

            if (timeLeft < 0.0f) {
                timeLeft = 0.0f;
                timerStarted = false;
                CloseWindow();
            }
        }

        // Draw
        BeginDrawing();

        ClearBackground(BLACK);

        // Draw texture
        DrawTexture(texture, screenWidth / 2 - texture.width / 2, screenHeight / 2 - texture.height / 2 - 50, WHITE);

        // Draw text box
        DrawRectangleRec(textBox, WHITE);
        DrawRectangleLinesEx(textBox, 2, BLACK);

        // Draw input text
        DrawText(name, (int)textBox.x + 5, (int)textBox.y + 8, 40, BLACK);

        // Draw input counter
        DrawText(TextFormat("INPUT CHARS: %i/%i", letterCount, MAX_INPUT_CHARS), screenWidth - 225, screenHeight - 50, 20, WHITE);

        // Draw timer
        if (timerStarted) {
            DrawText(TextFormat("Time remaining: %.2f", timeLeft), 10, 10, 20, RAYWHITE);
        }
        else {
            DrawText("Press SPACE to start the game", 10, 10, 20, RAYWHITE);
        }

        EndDrawing();

        // Handle game start
        if (IsKeyPressed(KEY_SPACE)) {
            time = (float)GetTime();
            timerStarted = true;
        }
    }

    // Unload resources
    UnloadTexture(texture);
    CloseWindow();
}
