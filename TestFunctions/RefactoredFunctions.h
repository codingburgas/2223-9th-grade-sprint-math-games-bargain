#pragma once


#include <string>
#include <iostream>
#include <Header.h>

using namespace std;

//refactored generateEquation function
string randomEquation(int a, int b, int op) {
    string equation;
    unsigned int solution;

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

    return equation;
}


//
float timerF(float time = 0.0f, float timeLeft = 0.0f)
{

    bool timerStarted = false;

    while (!WindowShouldClose()) {

        if (timerStarted) {
            float currentTime = (float)GetTime();
            timeLeft = 3.0f - (currentTime - time);

            if (timeLeft < 0.0f) {
                timeLeft = 0.0f;
                timerStarted = false;
                CloseWindow();
            }
        }

    }
    return 0;
}










