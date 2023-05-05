#include "thrust.h"

Thrust::Thrust(Sprite& sprite, Vec direction, Actor& defender, int damage)
    : Event{5},
      sprite{sprite},
      original{sprite},
      direction{direction},
      defender{defender},
      damage{damage} {}

void Thrust::execute(Engine&) {
    sprite.shift += direction * 3;
    sprite.angle += 45;
}

void Thrust::when_done(Engine& engine) {
    sprite = original;
    engine.events.add(Hit{defender, damage});
}