#include "dungeon.hpp"
#include "geo.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Dungeon::Dungeon() {
// }

// Dungeon::~Dungeon() {
// }


bool Dungeon::IsRoomInTheRightPlace(std::vector<Room> &rooms, Room room) {
    int i = 0;
    while (i < rooms.size()) {
        if (intersects(rooms[i].rect, room.rect)) {
            return false;
        } else {
            i++;
        }
    }
    return true;
}

void Dungeon::Generate()
{
    srand(time(0));
    int totalRooms = MIN_ROOMS + rand() % 5;
    for (int i = 0; i < totalRooms; i++)
    {
        Room room = MakeRoom(rooms);
        rooms.push_back(room);
    }
    std::cout << "Total rooms = ()" << rooms.size() << ")" << endl; 
}


vector<Position> Dungeon::GetSurface() {
    vector<Position> res = {};
    for (int r = 0; r < rooms.size(); r++) {
        for (int i = rooms[r].rect.position.x; i < rooms[r].rect.position.x + rooms[r].rect.width; i++) {
            for (int j = rooms[r].rect.position.y; j < rooms[r].rect.position.y + rooms[r].rect.height; j++) {
                res.push_back({i, j});
            }
        }
    }
    return res;
}

Room Dungeon::MakeRoom(std::vector<Room> &rooms)
{
    int width = 2 + rand() % 6;
    int height = 2 + rand() % 6;
    Position position = {15, 15};
    Room room = {{position, width, height}};
    if (rooms.size() > 0) {
        while (!IsRoomInTheRightPlace(rooms, room)) {
            int sign_x = (rand() % 2 == 1)? 1 : -1;
            int sign_y = (rand() % 2 == 1)? 1 : -1;
            position.x +=  sign_x * rand() % 5;
            position.y +=  sign_y * rand() % 5 ;
            room.rect.position = position;
        }
    }
    return room;
}

