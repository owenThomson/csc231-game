#include "mace.h"

#include "hit.h"

Mace::Mace(int damage) : Weapon{"mace", damage} {}

void Mace::use(Engine& engine, Actor& attacker, Actor& defender) {
    engine.events.add(Hit{defender, damage});
}
