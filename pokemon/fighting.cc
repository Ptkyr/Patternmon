#include "fighting.h"

Fighting::Fighting(Pokemon* p): PokemonDecorator(p) {}

void Fighting::hitBy(FlyingMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Fighting::hitBy(PsychicMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Fighting::hitBy(BugMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Fighting::hitBy(RockMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Fighting::hitBy(DarkMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Fighting::hitBy(FairyMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}
