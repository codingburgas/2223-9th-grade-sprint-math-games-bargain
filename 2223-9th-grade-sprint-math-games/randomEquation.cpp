#include "raylib.h"
#include <string>
#include "Header.h"

using namespace std;

void randomEquation()
{
    // Initialize window
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Binary Arithmetic");

    // Initialize variables
    int a = GetRandomValue(0, 15);
    int b = GetRandomValue(0, 15);
    int op = GetRandomValue(0, 3);
    string equation;
    unsigned int solution;

    // Loop until user exits
    while (!WindowShouldClose())
    {
        // Generate a new equation if user guessed correctly
        if (IsKeyPressed(KEY_ENTER))
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

        // Clear screen and draw equation
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText(equation.c_str(), 100, 100, 32, BLACK);
        EndDrawing();
    }

    // Clean up
    CloseWindow();

    
}