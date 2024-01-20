//
// Created by nishu on 24-11-2023.
//

#include "cgol.h"


int main(){
    event();
    return 1;
}

void createGrid() {

    int gap = WIDTH / ROWS;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < ROWS; j++) {
            Tile newTile;
            newTile.row = i;
            newTile.col = j;
            newTile.width = gap;
            newTile.x = newTile.row * newTile.width;
            newTile.y = newTile.col * newTile.width;
            newTile.alive = false;
            newTile.color = DEAD_COLOR;

            GRID_TILES[i][j] = newTile;
        }
    }
}

void drawGrid() {

    for (int i = 0; i < ROWS; ++i) {
        DrawLineV((Vector2) {0, (float) i * (float) GAP}, (Vector2) {(float) WIDTH, (float) i * (float) GAP},
                  BLACK);
        for (int j = 0; j < ROWS; ++j) {
            DrawLineV((Vector2) {(float) j * (float) GAP, (float) 0},
                      (Vector2) {(float) j * (float) GAP, (float) WIDTH}, BLACK);
        }
    }
}

void drawTiles() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < ROWS; ++j) {
            Tile currTile = GRID_TILES[j][i];

            DrawRectangle(currTile.x, currTile.y, currTile.width, currTile.width, currTile.color);

        }
    }

    drawGrid();

}


Vector2 getMousePos() {
    Vector2 pos;
    Vector2 mousePos = GetMousePosition();
    pos.x = mousePos.x / GAP;
    pos.y = mousePos.y / GAP;
    return pos;
}

void updateGrid(){
    for (int i = 0; i < ROWS; i++)
        for(int j = 0; j < ROWS; j++) {

            if (GRID_TILES[i][j].alive){
                GRID_TILES[i][j].color = DEAD_COLOR;
            } else{
                GRID_TILES[i][j].color = LIVE_COLOR;
            }
        }
    drawTiles();
}

void changeState() {
    Vector2 pos = getMousePos();
    int row = (int) pos.x;
    int col = (int) pos.y;

    Tile* curr = &GRID_TILES[row][col];

    curr->alive = true;
    curr->color = LIVE_COLOR;
}

void randomizer(){
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < ROWS; ++j) {
            if(GetRandomValue(1, 100) > 75)
                GRID_TILES[i][j].alive = true;
        }
    }
}


void event(){
    InitWindow(WIDTH, WIDTH, "Hello");


    createGrid();

    while (!WindowShouldClose()){
        BeginDrawing();


        if (IsKeyDown(KEY_B)) changeState();

        if (IsKeyPressed(KEY_SPACE)) algorithm();

        if (IsKeyPressed(KEY_ENTER)) createGrid();

        if (IsKeyPressed(KEY_R)) randomizer();
        updateGrid();
        ClearBackground(RAYWHITE);

        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();

}


