#pragma once

#include "action.h"

class Move : public Action {
public:
    Move() {}
    Result perform(Engine& engine) override;
};