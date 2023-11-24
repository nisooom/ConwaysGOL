//
// Created by nishu on 24-11-2023.
//

#ifndef CGOL_CGOL_H
#define CGOL_CGOL_H
#include "main.h"

int countAliveNeighbors(int x, int y) {
    int count = 0;
    int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
    int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

    for (int k = 0; k < 8; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx >= 0 && nx < ROWS && ny >= 0 && ny < ROWS && GRID_TILES[nx][ny].alive) {
            count++;
        }
    }

    return count;
}

void algorithm() {
    Tile newGrid[ROWS][ROWS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < ROWS; j++) {
            int aliveNeighbors = countAliveNeighbors(i, j);

            if (GRID_TILES[i][j].alive) {
                if (aliveNeighbors < 2 || aliveNeighbors > 3) {
                    newGrid[i][j].alive = false;
                } else {
                    newGrid[i][j].alive = true;
                }
            } else {
                if (aliveNeighbors == 3) {
                    newGrid[i][j].alive = true;
                } else {
                    newGrid[i][j].alive = false;
                }
            }

            newGrid[i][j].row = i;
            newGrid[i][j].col = j;
            newGrid[i][j].width = GAP;
            newGrid[i][j].x = i * GAP;
            newGrid[i][j].y = j * GAP;
            newGrid[i][j].color = newGrid[i][j].alive ? LIVE_COLOR : DEAD_COLOR;
        }
    }

    // Update GRID_TILES with the new state
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < ROWS; j++) {
            GRID_TILES[i][j] = newGrid[i][j];
        }
    }

    updateGrid();
}

#endif //CGOL_CGOL_H
