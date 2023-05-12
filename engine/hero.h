#pragma once

#include "action.h"
#include "actor.h"
#include "animatedsprite.h"
#include "herotype.h"

class Hero : public Actor {
public:
    Hero(Engine& engine, HeroType type, const Vec& position);
    virtual ~Hero() {}

    // orient hero towards direction
    void change_direction(const Vec& direction) override;

    // place hero at given position
    void move_to(const Vec& position) override;

    void attack(Actor& defender) override;
    void update() override;
    std::unique_ptr<Action> take_turn() override;
    std::vector<Sprite> get_sprites() const override;

    // called by engine when a button press or mouse click has taken place
    void handle_input(const std::string& key_name);

    HeroType type;

    bool invisible{false};
    int invisibility_duration{0};

private:
    // next action is set by engine via handle_input
    std::unique_ptr<Action> next_action;
    AnimatedSprite sprite;
};
