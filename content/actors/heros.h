#pragma once

#include "herotype.h"
#include "move.h"
#include "none.h"

namespace Heros {
// Reaction = std::function<std::unique_ptr<Action>()>
// std::unique_ptr do_stuff();
const std::unordered_map<std::string, Reaction> keybindings = {
    {"Left", []() { return std::make_unique<Move>(); }}

};

constexpr int default_speed{8};
const HeroType nobody{"wizard", default_speed, 1, std::make_shared<None>(), {}};

}  // namespace Heros
