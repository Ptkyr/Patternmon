#include "grass.h"

Grass::Grass(Pokemon* p): PokemonDecorator(p) {}

void Grass::hitBy(WaterMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Grass::hitBy(FireMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Grass::hitBy(GrassMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Grass::hitBy(ElectricMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Grass::hitBy(GroundMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Grass::hitBy(IceMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Grass::hitBy(PoisonMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Grass::hitBy(FlyingMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Grass::hitBy(BugMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}
