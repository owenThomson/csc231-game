#include "throw.h"

#include <cmath>

#include "engine.h"
#include "hit.h"

constexpr int duration = 10;

Throw::Throw(Sprite& sprite, Vec direction, Actor& defender, int damage)
    : Event{10},
      sprite{sprite},
      copy{sprite},
      direction{direction},
      defender{defender},
      damage{damage},
      starting_angle{sprite.angle} {
    if (direction == Vec{1, 0}) {
        starting_angle = 0;
        delta_angle = 540 / (duration - 1);

    } else if (direction == Vec{-1, 0}) {
        starting_angle = 0;
        delta_angle = -540 / (duration - 1);

    } else if (direction == Vec{0, 1}) {
        double sign = std::copysign(1.0, starting_angle);
        starting_angle = 45 * sign;
        delta_angle = -360 / (duration - 1) * sign;
        sprite.shift.y -= 32;
    } else if (direction == Vec{0, -1}) {
        double sign = std::copysign(1.0, starting_angle);
        starting_angle = 45 * sign;
        delta_angle = 360 / (duration - 1) * sign;
        sprite.shift.y += 16;
    }
}

void Throw::execute(Engine&) {
    sprite.shift += direction * 3;
    sprite.angle = starting_angle + delta_angle * frame_count;
}

void Throw::when_done(Engine& engine) {
    sprite = copy;
    engine.events.add(Hit{defender, damage});
}