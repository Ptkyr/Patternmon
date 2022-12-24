#include "poison.h"

Poison::Poison(Pokemon* p): PokemonDecorator(p) {}

void Poison::hitBy(GrassMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Poison::hitBy(FightingMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Poison::hitBy(PoisonMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Poison::hitBy(GroundMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Poison::hitBy(PsychicMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Poison::hitBy(BugMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Poison::hitBy(FairyMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}
