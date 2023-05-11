#include "sword.h"

#include "fire.h"
#include "hit.h"
#include "thrust.h"

Sword::Sword(int damage) : Weapon{"sword", damage} {}

void Sword::use(Engine& engine, Actor& attacker, Actor& defender) {
    // Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Fire{defender.get_position(), damage});
}
