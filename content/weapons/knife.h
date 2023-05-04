#pragma once
#include "engine.h"
#include "weapon.h"

class Knife : public Weapon {
public:
    Knife(int Damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};