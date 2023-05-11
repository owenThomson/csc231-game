#pragma once
#include "engine.h"
#include "weapon.h"

class Sword : public Weapon {
public:
    Sword(int Damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};