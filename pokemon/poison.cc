#include "poison.h"

Poison::Poison(Pokemon* ptr): PokemonDecorator(ptr) {}

void Poison::hitBy(GrassMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Poison::hitBy(FightingMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Poison::hitBy(PoisonMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Poison::hitBy(GroundMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Poison::hitBy(PsychicMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Poison::hitBy(BugMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Poison::hitBy(FairyMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}
