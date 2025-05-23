#pragma once

#include "grid.hpp"
#include "dungeon.hpp"

class DungeonMaker {
public:
    DungeonMaker(int row, int column, int cellSize): 
        grid(Grid{row, column, cellSize}), tmpGrid(Grid{row, column, cellSize}), dungeon(Dungeon{Grid{row, column, cellSize}}) {};
    void Update();
    void Draw();
    void FillGrid();
private:
    Grid grid;
    Grid tmpGrid;
    Dungeon dungeon;
};
