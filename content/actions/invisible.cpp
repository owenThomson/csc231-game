#include "invisible.h"

#include "engine.h"
#include "monster.h"
#include "randomness.h"
#include "rest.h"
#include "wandor.h"
// bool invisible{true};
Result Invisible::perform(Engine& engine) {
    if (engine.hero->invisible) {
        return failure();
    } else {
        engine.hero->invisible = true;

        return success();
    }

    // if (invisible) {
    //     return alternative(Wandor());
    // }
    // return success();
}