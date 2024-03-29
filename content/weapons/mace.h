#pragma once
#include "engine.h"
#include "weapon.h"

class Mace : public Weapon {
public:
    Mace(int Damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};