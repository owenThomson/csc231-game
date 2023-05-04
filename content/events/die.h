#pragma once
#include "engine.h"
class Die : public Event {
public:
    Die(Actor& actor);
    void execute(Engine& engine) override;

private:
    Actor& actor;
};