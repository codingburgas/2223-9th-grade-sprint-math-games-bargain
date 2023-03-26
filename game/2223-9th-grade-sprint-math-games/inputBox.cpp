#include "raylib.h"
#include <string>

#define MAX_INPUT_CHARS     9


using namespace std;

int input(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    bool questionAnswered = true;
    
   

    // Set up text box
    char name[MAX_INPUT_CHARS + 1] = "\0";
    int letterCount = 0;
    Rectangle textBox = { screenWidth / 2.0f - 385, 180, 225, 50 };

    // Correct answers
    short correctAnswers = 0;
    short wrongAnswers = 0;

    // Timer
    float time = 0.0f;
    
    
    
    string equation;
    string temp;
    unsigned int solution = 0;
    short answerType = 0;

    SetTargetFPS(10);               
    
    // Main game loop
    while (!WindowShouldClose())   
    {
        // Update
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
        if (IsKeyPressed(KEY_ENTER)) {
            questionAnswered = true;
            temp = to_string(solution);
            if (name == temp)
            {
                correctAnswers++;
                time += 5.0f;
                answerType = 1;
            }
            else
            {
                time -= 5.0f;
                answerType = 2;
                wrongAnswers++;
            }
        }
        
       
        // Draw text box
        DrawRectangleRec(textBox, WHITE);
        DrawRectangleLinesEx(textBox, 2, BLACK);

        // Draw input text
        DrawText(name, (int)textBox.x + 5, (int)textBox.y + 8, 40, BLACK);

        EndDrawing();
        
    }

    // De-Initialization
    
    CloseWindow();        
    

    return 0;
}
