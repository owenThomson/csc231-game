#include "mace.h"

#include "hit.h"
#include "thrust.h"

Mace::Mace(int damage) : Weapon{"mace", damage} {}

void Mace::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Thrust{sprite, direction, defender, damage});
}
