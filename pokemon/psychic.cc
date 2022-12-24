#include "psychic.h"

Psychic::Psychic(Pokemon* p): PokemonDecorator(p) {}

void Psychic::hitBy(FightingMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Psychic::hitBy(PsychicMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Psychic::hitBy(BugMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Psychic::hitBy(GhostMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Psychic::hitBy(DarkMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}
