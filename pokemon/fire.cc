#include "fire.h"

Fire::Fire(Pokemon* p): PokemonDecorator(p) {}

void Fire::hitBy(FireMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Fire::hitBy(WaterMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Fire::hitBy(GrassMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Fire::hitBy(IceMove& gm, const double mult) {
    p->hitBy(gm, mult * 0.5);
}

void Fire::hitBy(GroundMove& gm, const double mult) {
    p->hitBy(gm, mult * 2);
}

void Fire::hitBy(BugMove& gm, const double mult) {
    p->hitBy(gm, mult * 0.5);
}

void Fire::hitBy(RockMove& gm, const double mult) {
    p->hitBy(gm, mult * 2);
}

void Fire::hitBy(SteelMove& gm, const double mult) {
    p->hitBy(gm, mult * 0.5);
}

void Fire::hitBy(FairyMove& gm, const double mult) {
    p->hitBy(gm, mult * 0.5);
}
