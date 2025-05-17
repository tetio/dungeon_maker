#include <raylib.h>
#include <iostream>
#include "dungeon_maker.hpp"

int main()
{
    constexpr Color darkGray = {22, 22, 22, 255};

    constexpr int screenWidth = 750;
    constexpr int screenHeight = 750;
    constexpr int CELL_SIZE = 25;

    InitWindow(screenWidth, screenHeight, "Dungeon Maker");
    SetTargetFPS(12);

    DungeonMaker dm = DungeonMaker{30, 30, CELL_SIZE};
    dm.FillGrid();
    while (!WindowShouldClose())
    {
        // 1 - Event Handling
        if (IsKeyPressed(KEY_ENTER))
        {
            SetWindowTitle("Simulation is running ...");
        }
        else if (IsKeyPressed(KEY_SPACE))
        {
            dm.FillGrid();
            SetWindowTitle("Simulation is stopped");
        }
        // 2 - Update State
        dm.Update();
        // 3 - Drawing
        BeginDrawing();
            ClearBackground(darkGray);
            dm.Draw();
        EndDrawing();
    }

    CloseWindow();
}

