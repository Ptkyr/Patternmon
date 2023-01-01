#include "fighting.h"

Fighting::Fighting(Pokemon* ptr): PokemonDecorator(ptr) {}

void Fighting::hitBy(FlyingMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Fighting::hitBy(PsychicMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Fighting::hitBy(BugMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Fighting::hitBy(RockMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Fighting::hitBy(DarkMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Fighting::hitBy(FairyMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}
