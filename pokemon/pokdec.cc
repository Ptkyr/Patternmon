#include "pokdec.h"
#include "types.h"
#include <utility>

PokemonDecorator::PokemonDecorator(Pokemon* p): p{p} {}

PokemonDecorator::~PokemonDecorator() = default;

void PokemonDecorator::learn(std::shared_ptr<Move> m) {
    p->learn(m);
}

void PokemonDecorator::attack(Pokemon& p) const {
    this->p->attack(p);
}

void PokemonDecorator::hitBy(WaterMove& wm, const double mult) {
    p->hitBy(wm, mult);
}

void PokemonDecorator::hitBy(FireMove& wm, const double mult) {
    p->hitBy(wm, mult);
}

void PokemonDecorator::hitBy(GrassMove& wm, const double mult) {
    p->hitBy(wm, mult);
}

void PokemonDecorator::hitBy(ElectricMove& wm, const double mult) {
    p->hitBy(wm, mult);
}

void PokemonDecorator::hitBy(GroundMove& gm, const double mult) {
    p->hitBy(gm, mult);
}

void PokemonDecorator::hitBy(NormalMove& gm, const double mult) {
    p->hitBy(gm, mult);
}

void PokemonDecorator::hitBy(IceMove& gm, const double mult) {
    p->hitBy(gm, mult);
}

void PokemonDecorator::hitBy(FightingMove& gm, const double mult) {
    p->hitBy(gm, mult);
}

void PokemonDecorator::hitBy(PoisonMove& gm, const double mult) {
    p->hitBy(gm, mult);
}

void PokemonDecorator::hitBy(FlyingMove& gm, const double mult) {
    p->hitBy(gm, mult);
}

void PokemonDecorator::hitBy(PsychicMove& gm, const double mult) {
    p->hitBy(gm, mult);
}

void PokemonDecorator::hitBy(BugMove& gm, const double mult) {
    p->hitBy(gm, mult);
}

void PokemonDecorator::hitBy(RockMove& gm, const double mult) {
    p->hitBy(gm, mult);
}

void PokemonDecorator::hitBy(GhostMove& gm, const double mult) {
    p->hitBy(gm, mult);
}

void PokemonDecorator::hitBy(DragonMove& gm, const double mult) {
    p->hitBy(gm, mult);
}

void PokemonDecorator::hitBy(DarkMove& gm, const double mult) {
    p->hitBy(gm, mult);
}

void PokemonDecorator::hitBy(SteelMove& gm, const double mult) {
    p->hitBy(gm, mult);
}

void PokemonDecorator::hitBy(FairyMove& gm, const double mult) {
    p->hitBy(gm, mult);
}
