#include "monsters.h"

#include "none.h"
#include "rest.h"

namespace Monsters {
std::unique_ptr<Action> default_behavior(Engine&, Monster&) {
    return std::make_unique<Rest>();
}

constexpr int default_speed{8};

MonsterType goblin() {
    int health = 2;
    return {"goblin", default_speed, health, std::make_shared<None>(),
            default_behavior};
}
}  // namespace Monsters
