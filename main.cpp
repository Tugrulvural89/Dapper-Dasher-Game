#include <iostream>
#include "raylib/src/raylib.h"
int main()
{
    const int screenWidth{1000};
    const int screenHeight{1000};
    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - basic shapes");

    SetTargetFPS(60);


    Texture2D scrafy = LoadTexture("C:/Users/Shadow/CLionProjects/RaylibProject/textures/scarfy.png");
    Vector2 scrafySize;
    Rectangle scrafyRec;

    scrafyRec.height = scrafy.height;
    scrafyRec.width = scrafy.width/6;
    scrafyRec.x = 0;
    scrafyRec.y = 0;

    scrafySize.x = screenWidth/2 - scrafyRec.width/2;
    scrafySize.y = screenHeight - scrafyRec.height;



    int velocity{60};
    int gravity{1'000};

    bool isJumping{false};
    const int jumpeValue = -600;

    int frame{};

    const float updateTime = 1.0f / 3.0f;
    float runningTime{};
    while (!WindowShouldClose())
        {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            const float dT{GetFrameTime()};
            if (scrafySize.y >= screenHeight - scrafyRec.height)
            {
                isJumping = false;
                velocity = 0;
            } else
            {
                isJumping = true;
                velocity += gravity * dT;
            }
            if (IsKeyPressed(KEY_SPACE) && !isJumping)
            {
                velocity += jumpeValue;
            }


            runningTime += dT;
            if (runningTime >= updateTime)
            {
                scrafySize.y += velocity * dT;
                scrafyRec.x = frame * scrafyRec.width;
                frame++;
                if (frame > 5) frame = 0;
            }


            DrawTextureRec(scrafy, scrafyRec, scrafySize, WHITE);
            EndDrawing();
        }
    UnloadTexture(scrafy);
    CloseWindow();
}
