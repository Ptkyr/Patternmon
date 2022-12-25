#include "steel.h"

Steel::Steel(Pokemon* p): PokemonDecorator(p) {}

void Steel::hitBy(NormalMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Steel::hitBy(FireMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Steel::hitBy(GrassMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Steel::hitBy(IceMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Steel::hitBy(FightingMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Steel::hitBy(PoisonMove& wm, const double mult) {
    p->hitBy(wm, mult * 0);
}

void Steel::hitBy(GroundMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Steel::hitBy(FlyingMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Steel::hitBy(PsychicMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Steel::hitBy(BugMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Steel::hitBy(RockMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Steel::hitBy(DragonMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Steel::hitBy(SteelMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Steel::hitBy(FairyMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}
