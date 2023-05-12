#include "invisible.h"

#include "randomness.h"
#include "rest.h"
#include "wandor.h"

Result perform(Engine&) {
    if (probability(50)) {
        return alternative(Wandor());
    } else {
        return alternative(Rest());
    }
}