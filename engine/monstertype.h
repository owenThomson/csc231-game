#pragma once

#include "weapon.h"

#include <string>
#include <memory>
#include <functional>

// forward declarations
class Action;
class Engine;
class Monster;

struct MonsterType {
    std::string sprite_name;
    int speed, max_health;
    std::shared_ptr<Weapon> weapon;
    std::function<std::unique_ptr<Action>(Engine& engine, Monster& monster)> behavior;
};
