#include "dungeon.hpp"

// Dungeon::Dungeon() {
// }

// Dungeon::~Dungeon() {
// }

void Dungeon::Generate() {
    srand(time(0));
    int totalRooms = MIN_ROOMS + rand() % 5;
    for (int i = 0; i < totalRooms; i++) {
        Room room = MakeRoom();
        rooms.push_back(room);
    }

}

Room Dungeon::MakeRoom() {
    int width = 2 + rand() % 6;
    int height = 2 + rand() % 6;
    Position position = grid.GetRandomPosition(width, height);
    return Room{position, width, height};
}