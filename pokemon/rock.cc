#include "rock.h"

Rock::Rock(Pokemon* p): PokemonDecorator(p) {}

void Rock::hitBy(NormalMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Rock::hitBy(FireMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Rock::hitBy(WaterMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Rock::hitBy(GrassMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Rock::hitBy(FightingMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Rock::hitBy(PoisonMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Rock::hitBy(GroundMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Rock::hitBy(FlyingMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Rock::hitBy(SteelMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}
