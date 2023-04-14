#include "move.h"

#include <iostream>

#include "actor.h"

Result Move::perform(Engine&) {
    Vec position = actor->get_position();
    std::cout << position << "\n";
    success();
}