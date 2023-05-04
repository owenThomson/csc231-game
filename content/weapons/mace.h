#pragma once

#include "engine.h"
#include "weapon.h"

class Mace : public Weapon {
public:
    Mace(int Damagae);
    void use(Engine& engine, Actor&, Actor& defender) override;
};