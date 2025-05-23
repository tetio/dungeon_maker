#pragma once

struct Position
{
    int x;
    int y;
};

struct Rect {
    Position position; // top left corner
    int width;
    int height;
};

bool intersects(Rect r1, Rect r2);