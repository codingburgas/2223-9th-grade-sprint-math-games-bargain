#include "raylib.h"
#include "Header.h"
#include <string>

using namespace std;

#define MAX_INPUT_CHARS 9

void game(float setTime, int inGameQuestions)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    
    bool questionAnswered = false;
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
    
    // Correct answers
    short correctAnswers = 0;

    // Timer
    float time = 0.0f;
    float timeLeft = 0.0f;

    int a = GetRandomValue(0, 15);
    int b = GetRandomValue(0, 15);
    int op = GetRandomValue(0, 3);
    string equation;

    unsigned int solution;

    // Loop until user exits

        // Generate a new equation if user guessed correctly
    if (questionAnswered != true)
    {
        a = GetRandomValue(0, 15);
        b = GetRandomValue(0, 15);
        op = GetRandomValue(0, 4);

        if (op == 0)
        {
            equation = to_string(a) + " & " + to_string(b) + " = ?";
            solution = a & b;
        }
        else if (op == 1)
        {
            equation = to_string(a) + " | " + to_string(b) + " = ?";
            solution = a | b;
        }
        else if (op == 2)
        {
            equation = to_string(a) + " ^ " + to_string(b) + " = ?";
            solution = a ^ b;
        }
        else if (op == 3)
        {
            equation = to_string(a) + " << " + to_string(b) + " = ?";
            solution = a << b;
        }
        else if (op == 4)
        {
            equation = to_string(a) + " >> " + to_string(b) + " = ?";
            solution = a >> b;
        }
    }

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
        timeLeft = setTime + 7.5f - (currentTime - time);
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
        DrawText(TextFormat("Time left: %.0f", timeLeft), 240, 30, 50, RAYWHITE);


        DrawText(equation.c_str(), 100, 100, 20, RAYWHITE);
        // Draw correct answers
        DrawText(TextFormat("Correct answers: %d", correctAnswers), screenWidth - 250, screenHeight - 25, 25, RAYWHITE);

        EndDrawing();
    }
    // Unload resources
    UnloadTexture(texture);
    CloseWindow();
}
