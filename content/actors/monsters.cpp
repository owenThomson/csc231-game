#include "monsters.h"

#include "engine.h"
#include "hammer.h"
#include "knife.h"
#include "monster.h"
#include "move.h"
#include "none.h"
#include "randomness.h"
#include "rest.h"
#include "wandor.h"

namespace Monsters {
std::unique_ptr<Action> default_behavior(Engine& engine, Monster& me) {
    if (me.is_visible() && engine.hero) {
        std::vector<Vec> path = engine.dungeon.calculate_path(
            me.get_position(), engine.hero->get_position());
        if (path.size() > 1) {
            Vec direction = path.at(1) - path.at(0);
            return std::make_unique<Move>(direction);
        }
    }

    // Also would be cool to have little mascot follow behind hero

    // maybe make this happen when hero is invisible
    if (probability(66)) {
        return std::make_unique<Wandor>();
    } else {
        return std::make_unique<Rest>();
    }
}

constexpr int default_speed{8};

MonsterType goblin() {
    int health = 8;
    return {"goblin", default_speed, health, std::make_shared<Hammer>(1),
            default_behavior};
}

MonsterType orc() {
    int health = 2;
    return {"orc", default_speed, health, std::make_shared<Knife>(2),
            default_behavior};
}

MonsterType skeleton() {
    int health = 2;
    return {"skeleton", default_speed, health, std::make_shared<Hammer>(2),
            default_behavior};
}

}  // namespace Monsters
