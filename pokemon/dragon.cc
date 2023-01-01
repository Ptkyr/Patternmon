#include "dragon.h"

Dragon::Dragon(Pokemon* ptr): PokemonDecorator(ptr) {}

void Dragon::hitBy(FireMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Dragon::hitBy(WaterMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Dragon::hitBy(GrassMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Dragon::hitBy(ElectricMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Dragon::hitBy(IceMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Dragon::hitBy(DragonMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Dragon::hitBy(FairyMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}
