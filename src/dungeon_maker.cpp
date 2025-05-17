#include "dungeon_maker.hpp"

#include <time.h>
#include <cstdlib>
// #include <iostream>
#include "grid.hpp"

void DungeonMaker::FillGrid()
{
    srand(time(0));
    // std::cout << "POt" << std::endl;
    for (int row = 0; row < grid.GetRows(); row++)
    {
        for (int column = 0; column < grid.GetColumns(); column++)
        {
            grid.SetValue(row, column, rand() % 2);
        }
    }
}

void DungeonMaker::Update() {

}

void DungeonMaker::Draw() {
    grid.Draw();
}
