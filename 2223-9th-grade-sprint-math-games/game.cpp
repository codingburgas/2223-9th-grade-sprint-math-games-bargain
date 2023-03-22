#include "raylib.h"
#include "Header.h"
#define MAX_INPUT_CHARS     9

void game()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [textures] example - image loading");

    // NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)

    Image image = LoadImage("c4.png");     // Loaded in CPU memory (RAM)
    ImageResize(&image, 350, 400);
    Texture2D texture = LoadTextureFromImage(image);          // Image converted to texture, GPU memory (VRAM)
    UnloadImage(image);

    char name[MAX_INPUT_CHARS + 1] = "\0";      // NOTE: One extra space required for null terminator char '\0'
    int letterCount = 0;

    Rectangle textBox = { screenWidth / 2.0f - 100, 180, 225, 50 };
    bool mouseOnText = false;

    int framesCounter = 0;

    float time = 0.0f;
    float timeLeft = 0.0f;
    bool timerStarted = false;

    while (!WindowShouldClose()) {

        if (CheckCollisionPointRec(GetMousePosition(), textBox)) mouseOnText = true;
        else mouseOnText = false;

        if (mouseOnText)
        {
            // Set the window's cursor to the I-Beam
            SetMouseCursor(MOUSE_CURSOR_IBEAM);

            // Get char pressed (unicode character) on the queue
            int key = GetCharPressed();

            // Check if more characters have been pressed on the same frame
            while (key > 0)
            {
                // NOTE: Only allow keys in range [32..125]
                if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS))
                {
                    name[letterCount] = (char)key;
                    name[letterCount + 1] = '\0'; // Add null terminator at the end of the string.
                    letterCount++;
                }

                key = GetCharPressed();  // Check next character in the queue
            }

            if (IsKeyPressed(KEY_BACKSPACE))
            {
                letterCount--;
                if (letterCount < 0) letterCount = 0;
                name[letterCount] = '\0';
            }
        }
        else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

        if (mouseOnText) framesCounter++;
        else framesCounter = 0;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        DrawText("PLACE MOUSE OVER INPUT BOX!", 240, 140, 20, GRAY);

        DrawRectangleRec(textBox, LIGHTGRAY);
        if (mouseOnText) DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, RED);
        else DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, DARKGRAY);

        DrawText(name, (int)textBox.x + 5, (int)textBox.y + 8, 40, MAROON);

        DrawText(TextFormat("INPUT CHARS: %i/%i", letterCount, MAX_INPUT_CHARS), 315, 250, 20, DARKGRAY);

        if (mouseOnText)
        {
            if (letterCount < MAX_INPUT_CHARS)
            {
                // Draw blinking underscore char
                if (((framesCounter / 20) % 2) == 0) DrawText("_", (int)textBox.x + 8 + MeasureText(name, 40), (int)textBox.y + 12, 40, MAROON);
            }
            else DrawText("Press BACKSPACE to delete chars...", 230, 300, 20, GRAY);
        }

        EndDrawing();

        bool keyPressed = false;
        int key = GetKeyPressed();

        if ((key >= 32) && (key <= 126)) keyPressed = true;

        keyPressed;



        BeginDrawing();

        ClearBackground(BLACK);

        DrawTexture(texture, screenWidth / 2 - texture.width / 2, screenHeight / 2 - texture.height / 2, WHITE);



        EndDrawing();



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
        if (timerStarted) {
            DrawText(TextFormat("Time remaining: %.2f", timeLeft), 10, 10, 20, RAYWHITE);
        }
        else {
            DrawText("Press SPACE to start the game", 10, 10, 20, RAYWHITE);
        }
        EndDrawing();


        if (IsKeyPressed(KEY_SPACE)) {
            time = (float)GetTime();
            timerStarted = true;

        }


    }


}