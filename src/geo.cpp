#include "geo.hpp"
#include <array>

bool check_point(int p1, int p, int offset)
{
    return (p >= p1 && p <= p1 + offset);
}

bool intersects(Rect r1, Rect r2)
{
    std::array<Position, 4> points = {{{r2.position.x, r2.position.y},
                                       {r2.position.x + r2.width, r2.position.y},
                                       {r2.position.x, r2.position.y + r2.height},
                                       {r2.position.x + r2.width, r2.position.y + r2.height}}};
    for (int i = 0; i < 4; i++)
    {
        if (check_point(r1.position.x-1, points[i].x, r1.width+1) &&
            check_point(r1.position.y-1, points[i].y, r1.height+1))
        {
            return true;
        }
    }
    return false;
}
