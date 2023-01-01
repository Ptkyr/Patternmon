#include "normal.h"

Normal::Normal(Pokemon* ptr): PokemonDecorator(ptr) {}

void Normal::hitBy(FightingMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Normal::hitBy(GhostMove& wm, const double mult) {
    p->hitBy(wm, mult * IMMUNITY);
}
