#pragma once

#include "herotype.h"
#include "none.h"

namespace Heros {

constexpr int default_speed{8};
const HeroType nobody{"wizard", default_speed, 1, std::make_shared<None>(), {}};

}  // namespace Heros
