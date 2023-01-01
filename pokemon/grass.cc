#include "grass.h"

Grass::Grass(Pokemon* ptr): PokemonDecorator(ptr) {}

void Grass::hitBy(FireMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Grass::hitBy(WaterMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Grass::hitBy(GrassMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Grass::hitBy(ElectricMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Grass::hitBy(GroundMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Grass::hitBy(IceMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Grass::hitBy(PoisonMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Grass::hitBy(FlyingMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Grass::hitBy(BugMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}
