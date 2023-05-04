#include "hammer.h"

#include "hit.h"
Hammer::Hammer(int damage) : Weapon{"hammer", damage} {}

void Hammer::use(Engine& engine, Actor& attacker, Actor& defender) {
    engine.events.add(Hit{defender, damage});
}
