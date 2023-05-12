#pragma once

#include "closedoor.h"
#include "hammer.h"
#include "herotype.h"
#include "knife.h"
#include "mace.h"
#include "move.h"
#include "rest.h"
#include "sword.h"

namespace Heros {
// Reaction = std::function<std::unique_ptr<Action>()>
// std::unique_ptr do_stuff();
const std::unordered_map<std::string, Reaction> keybindings = {
    {"Left",
     []() {
         return std::make_unique<Move>(Vec{-1, 0});
     }},
    {"Right",
     []() {
         return std::make_unique<Move>(Vec{1, 0});
     }},
    {"Up",
     []() {
         return std::make_unique<Move>(Vec{0, 1});
     }},
    {"Down",
     []() {
         return std::make_unique<Move>(Vec{0, -1});
     }},
    {"R", []() { return std::make_unique<Rest>(); }},
    {"C", []() { return std::make_unique<CloseDoor>(); }},

};

constexpr int default_speed{8};
const HeroType nobody{"wizard", default_speed, 100, std::make_shared<Sword>(4),
                      keybindings};

}  // namespace Heros
