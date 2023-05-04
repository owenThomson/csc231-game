#pragma once

#include "engine.h"
#include "weapon.h"

class Hammer : public Weapon {
public:
    Hammer(int Damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};