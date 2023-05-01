#include "opendoor.h"

#include <iostream>

#include "actor.h"
#include "engine.h"
#include "updatefov.h"

Result OpenDoor::perform(Engine& engine) {
    Tile& tile = engine.dungeon.tiles(position);
    if (tile.is_door()) {
        Door& door = engine.dungeon.doors.at(position);
        door.open();
        tile.walkable = true;
        engine.events.add(UpdateFOV{});
        return success();
    }
}

OpenDoor::OpenDoor(Vec position) : position{position} {}