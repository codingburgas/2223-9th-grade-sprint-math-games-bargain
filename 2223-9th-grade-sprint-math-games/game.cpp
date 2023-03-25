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
    Texture2D background = LoadTexture("../assets/game-bg.png");
    UnloadImage(image);

    // Set up text box
    char name[MAX_INPUT_CHARS + 1] = "\0";
    int letterCount = 0;
    Rectangle textBox = { screenWidth / 2.0f - 385, 180, 225, 50 };

    // Timer
    float time = 0.0f;
    float timeLeft = 0.0f;

    while (!WindowShouldClose()) {
        DrawTexture(background, 0, 0, WHITE);

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
        float currentTime = (float)GetTime();
        timeLeft = 66.0f - (currentTime - time);
        if (timeLeft < 0.0f) {
                timeLeft = 0.0f;
                
                CloseWindow();
            }

        // Draw
        BeginDrawing();

        ClearBackground(BLACK);

        // Draw texture
        DrawTexture(texture, screenWidth / 2 - texture.width / 2, screenHeight / 2 - texture.height / 2, WHITE);

        // Draw text box
        DrawRectangleRec(textBox, WHITE);
        DrawRectangleLinesEx(textBox, 2, BLACK);

        // Draw input text
        DrawText(name, (int)textBox.x + 5, (int)textBox.y + 8, 40, BLACK);


        // Draw timer
        DrawText(TextFormat("Time left: %.0f", timeLeft), 337, 10, 20, RAYWHITE);
        

        EndDrawing();
    }
    // Unload resources
    UnloadTexture(texture);
    CloseWindow();
}
