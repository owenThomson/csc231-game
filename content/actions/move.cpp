#include "move.h"

#include <iostream>

#include "actor.h"
#include "engine.h"

Move::Move(Vec direction) : direction{direction} {}

Result Move::perform(Engine& engine) {
    Vec position = actor->get_position() + direction;

    // bool is_even = (position.x + position.y) % 2 == 0;

    // for (auto& [p, door] : engine.dungeon.doors) {
    //     if (is_even) {
    //         door.open();
    //     } else {
    //         door.close();
    //     }
    // }

    Tile& tile = engine.dungeon.tiles(position);
    if (tile.is_wall()) {
        return failure();
    }
    if (tile.is_door()) {
        return failure();
    }
    actor->move_to(position);
    return success();
}