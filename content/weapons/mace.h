#pragma once

#include "weapon.h"

class Mace : public Weapon {
public:
    Mace(int Damagae);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};