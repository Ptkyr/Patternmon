#include "electric.h"

Electric::Electric(Pokemon* p): PokemonDecorator(p) {}

void Electric::hitBy(ElectricMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Electric::hitBy(GroundMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}
