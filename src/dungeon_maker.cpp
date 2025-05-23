#include "dungeon_maker.hpp"

#include <time.h>
#include <cstdlib>
// #include <iostream>
#include "grid.hpp"

void DungeonMaker::FillGrid()
{
    srand(time(0));

    dungeon.Generate();    
    vector<Position> tiles = dungeon.GetSurface();

    // std::cout << "POt" << std::endl;
    for (int row = 0; row < grid.GetRows(); row++)
    {
        for (int column = 0; column < grid.GetColumns(); column++)
        {
            grid.SetValue(row, column, 0);
        }
    }
    for (int i = 0; i < tiles.size(); i++) {
        grid.SetValue(tiles[i].x, tiles[i].y, 1);
    }

}

void DungeonMaker::Update() {

}

void DungeonMaker::Draw() {
    grid.Draw();
}
