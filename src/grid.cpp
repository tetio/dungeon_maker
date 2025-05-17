#include <raylib.h>
#include <cstdlib>
#include <ctime>
#include "grid.hpp"

void Grid::Draw()
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            Color color = cells[row][column] ? Color{0, 255, 0, 255} : Color{66, 66, 66, 255};
            DrawRectangle(column * cellSize, row * cellSize, cellSize - 1, cellSize - 1, color);
        }
    }
}

int Grid::GetRows()
{
    return rows;
}

int Grid::GetColumns()
{
    return columns;
}

void Grid::SetValue(int row, int column, int value)
{
    if (row >= 0 && row < rows && column >= 0 && column < columns)
    {
        cells[row][column] = value;
    }
}

int Grid::GetCellValue(int row, int column)
{
    return cells[row][column];
}

Position Grid::GetRandomPosition(int width, int height) {
    srand(time(0));

    int x = rand() % cells.size() - width;
    int y = rand() % cells[0].size() - height;

    return Position{(x < 0)? 0 : x, (y < 0)? 0 : y};
}


