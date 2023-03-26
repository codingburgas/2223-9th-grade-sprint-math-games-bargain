#include "raylib.h"
#include "Header.h"
void picture()
{
    
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [textures] example - image loading");

   

    Image image = LoadImage("c4.png");     
    ImageResize(&image, 350, 400);
    Texture2D texture = LoadTextureFromImage(image);          // Image converted to texture
    UnloadImage(image);   

    SetTargetFPS(60);     

    
    while (!WindowShouldClose())    
    {
       
        BeginDrawing();

        ClearBackground(BLACK);

        DrawTexture(texture, screenWidth / 2 - texture.width / 2, screenHeight / 2 - texture.height / 2, WHITE);

        

        EndDrawing();
       
    }

    
    UnloadTexture(texture);      

    CloseWindow();               
    

    
}