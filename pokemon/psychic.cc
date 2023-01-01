#include "psychic.h"

Psychic::Psychic(Pokemon* p): PokemonDecorator(p) {}

void Psychic::hitBy(FightingMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Psychic::hitBy(PsychicMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Psychic::hitBy(BugMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Psychic::hitBy(GhostMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Psychic::hitBy(DarkMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}
