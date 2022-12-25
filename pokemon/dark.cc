#include "dark.h"

Dark::Dark(Pokemon* p): PokemonDecorator(p) {}

void Dark::hitBy(FightingMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Dark::hitBy(PsychicMove& wm, const double mult) {
    p->hitBy(wm, mult * 0);
}

void Dark::hitBy(BugMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Dark::hitBy(GhostMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Dark::hitBy(DarkMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Dark::hitBy(FairyMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}
