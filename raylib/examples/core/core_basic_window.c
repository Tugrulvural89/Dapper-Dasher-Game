/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2023 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

int main()
{
    int screen_width = 600;
    int screen_height = 500;
    InitWindow(screen_width, screen_height, "Helloo This Is My Text!");
    
    // circle coordinates
    int circle_x = 0;
    int circle_y = 0;
    int circle_radius = 25;
    
    // axe y value
    int axe_y = 0; //middle screen
    int axe_x = 300;
    int axe_length = 50;
    
    int l_circle_x = circle_x - circle_radius;
    int r_circle_x = circle_x + circle_radius;
    int u_circle_y = circle_y - circle_radius;
    int b_circle_y = circle_y + circle_radius;

    int u_axe_y = axe_y;
    int b_axe_y = axe_y + axe_length;
    int l_axe_x = axe_x;
    int r_axe_x = axe_x + axe_length;

    
    bool collision_with_axe = 
                        (b_axe_y >= u_circle_y) && 
                        (u_axe_y <= b_circle_y) && 
                        (r_axe_x >= l_circle_x) && 
                        (l_axe_x <= r_circle_x);

    
    
    int direction = 10;
    SetTargetFPS(60);
    while (WindowShouldClose() != true)
    {
        BeginDrawing();
        ClearBackground(WHITE);
        
        if(collision_with_axe)
        {
            DrawText("Game Over!", 300, 100, 22, RED);
        } else {
            
                        // Game logic begins

            // update the edges
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;
            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;
            // update collision_with_axe
            collision_with_axe = 
                        (b_axe_y >= u_circle_y) && 
                        (u_axe_y <= b_circle_y) && 
                        (r_axe_x >= l_circle_x) && 
                        (l_axe_x <= r_circle_x);

                 // Game Logic Begins
            DrawCircle(circle_x, circle_y, circle_radius, BLUE);
            DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED);
            //axe_y = axe_y + 10;
            axe_y +=direction;
  
            if (axe_y > 500 || axe_y < 0)
            {
                direction = -direction;
            }
            if (IsKeyDown(KEY_D) && circle_x < screen_width)
            {
                circle_x += 10;
            }
            if (IsKeyDown(KEY_A) && circle_x > 0)
            {
                circle_x -= 10;
            }

           
            // Game Logic Ends
        }
       
        EndDrawing();
    }
}