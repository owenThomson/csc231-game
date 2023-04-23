#include "closedoor.h"

#include <iostream>

#include "actor.h"
#include "engine.h"

bool closed_any_doors{false};
bool walkable{true};
Result CloseDoor::perform(Engine& engine) {
    Vec position = actor->get_position();
    std::vector<Vec> neighbors = engine.dungeon.neighbors(position);
    for (Vec neighbor : neighbors) {
        Tile& tile = engine.dungeon.tiles(neighbor);
        if (tile.is_door()) {
            Door& door = engine.dungeon.doors.at(neighbor);
            door.close();
            closed_any_doors = true;
            tile.walkable = false;
        }
    }
    if (closed_any_doors) {
        return success();
    } else {
        return failure();
    }
}