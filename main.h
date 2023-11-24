//
// Created by nishu on 24-11-2023.
//

#ifndef CONWAYSGOL_MAIN_H
#define CONWAYSGOL_MAIN_H
#include "raylib.h"
#include "stdbool.h"
#include "stdio.h"


#define WIDTH 600
#define HEIGHT 600
#define ROWS 20

#define GAP (int)(WIDTH/ROWS)

typedef struct Tile {
    int row, col;
    int x, y, width;
    Color color;
    bool alive;
} Tile;


Tile GRID_TILES[ROWS][ROWS];

Color DEAD_COLOR = BLACK;
Color LIVE_COLOR = WHITE;




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


#endif //CONWAYSGOL_MAIN_H
