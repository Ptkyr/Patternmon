#include "dark.h"

Dark::Dark(Pokemon* ptr): PokemonDecorator(ptr) {}

void Dark::hitBy(FightingMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Dark::hitBy(PsychicMove& wm, const double mult) {
    p->hitBy(wm, mult * IMMUNITY);
}

void Dark::hitBy(BugMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Dark::hitBy(GhostMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Dark::hitBy(DarkMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Dark::hitBy(FairyMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}
