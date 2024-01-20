//
// Created by nishu on 24-11-2023.
//

#ifndef CONWAYSGOL_MAIN_H
#define CONWAYSGOL_MAIN_H
#include "raylib.h"
#include "stdbool.h"
#include "stdio.h"
#include "cgol.h"

#define WIDTH 600
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

void createGrid();
void drawGrid();
void drawTiles();
Vector2 getMousePos();
void updateGrid();
void changeState();
void randomizer();
void event();

#endif //CONWAYSGOL_MAIN_H
