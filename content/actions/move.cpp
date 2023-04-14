#include "move.h"

#include <iostream>

#include "actor.h"

Move::Move(Vec direction) : direction{direction} {}

Result Move::perform(Engine&) {
    Vec position = actor->get_position();
    std::cout << position << "\n";
    return success();
}