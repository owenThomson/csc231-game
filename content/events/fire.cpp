
#include "fire.h"

#include "engine.h"
#include "hit.h"

Fire::Fire(Vec position, int damage) : position{position}, damage{damage} {}
void Fire::execute(Engine& engine) {
    if (frame_count == 0) {
        sprite = engine.graphics.get_animated_sprite("magic", 1);
        sprite.shift(Vec{0, 20});
        number_of_frames = sprite.number_of_frames() * .5;
    }

    engine.camera.add_overlay(position, sprite.get_sprite());
    if (frame_count % 2 == 0) {
        sprite.update();
    }
}

void Fire::when_done(Engine& engine) {
    Tile& tile = engine.dungeon.tiles(position);
    if (tile.actor) {
        engine.events.add(Hit{*tile.actor, damage});
    }
}