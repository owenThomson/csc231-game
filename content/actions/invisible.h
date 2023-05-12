#pragma once

#include "action.h"

class Invisible : public Action {
public:
    Result perform(Engine&) override;
};