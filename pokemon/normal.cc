#include "normal.h"

Normal::Normal(Pokemon* p): PokemonDecorator(p) {}

void Normal::hitBy(FightingMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Normal::hitBy(GhostMove& wm, const double mult) {
    p->hitBy(wm, mult * IMMUNITY);
}
