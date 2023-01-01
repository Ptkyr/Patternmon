#include "electric.h"

Electric::Electric(Pokemon* ptr): PokemonDecorator(ptr) {}

void Electric::hitBy(ElectricMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Electric::hitBy(GroundMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Electric::hitBy(FlyingMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}
