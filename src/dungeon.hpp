#include <vector>
#include "grid.hpp"
#include "position.h"

using namespace std;

const int MIN_ROOMS = 6;


struct Room {
    Position position;
    int width;
    int height;
};

class Dungeon {
public:
    Dungeon(Grid grid): grid(grid), rooms() {}
    void Generate();
private:
    Grid grid;
    vector<Room> rooms;
    Room MakeRoom();
};