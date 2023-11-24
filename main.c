//
// Created by nishu on 24-11-2023.
//

#include "main.h"
#include "cgol.h"

int main(){
    InitWindow(WIDTH, HEIGHT, "Hello");

    createGrid();

    while (!WindowShouldClose()){
        BeginDrawing();


        if (IsKeyDown(KEY_B)) changeState();

        if (IsKeyPressed(KEY_SPACE)) algorithm();
        updateGrid();
        ClearBackground(RAYWHITE);

        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();
    return 1;
}

