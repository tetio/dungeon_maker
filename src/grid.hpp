#pragma once
#include <vector>
#include "position.h"

using namespace std;

class Grid
{
public:
    Grid(int rows, int columns, int cellSize) 
            : rows(rows), columns(columns), cellSize(cellSize), cells(rows, std::vector<int>(columns, 0)) {};
    void Draw();
    int GetRows();
    int GetColumns();
    void SetValue(int row, int column, int value);
    int GetCellValue(int row, int column);
    Position GetRandomPosition(int width, int height);

private:
    int rows;
    int columns;
    int cellSize;
    vector<vector<int>> cells;
};