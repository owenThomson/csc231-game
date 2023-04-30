#pragma once

#include "action.h"
#include "monstertype.h"

namespace Monsters {
std::unique_ptr<Action> default_behavior(Engine& engine, Monster& monster);
MonsterType goblin();
MonsterType skeleton();

}  // namespace Monsters
