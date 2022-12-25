#include "dragon.h"

Dragon::Dragon(Pokemon* p): PokemonDecorator(p) {}

void Dragon::hitBy(FireMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Dragon::hitBy(WaterMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Dragon::hitBy(GrassMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Dragon::hitBy(ElectricMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Dragon::hitBy(IceMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Dragon::hitBy(DragonMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Dragon::hitBy(FairyMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}
