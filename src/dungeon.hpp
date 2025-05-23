#include <vector>
#include "grid.hpp"
#include "geo.hpp"

using namespace std;

const int MIN_ROOMS = 6;


struct Room {
    Rect rect;
};

class Dungeon {
public:
    Dungeon(Grid grid): grid(grid), rooms({}) {}
    void Generate();
    vector<Position> GetSurface();
private:
    Grid grid;
    vector<Room> rooms;
    Room MakeRoom(vector<Room> &rooms);
    bool IsRoomInTheRightPlace(std::vector<Room> &rooms, Room room);
};