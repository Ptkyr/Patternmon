#include "pokdec.h"
#include "move.h"
#include <utility>

const double IMMUNITY = 0;
const double NVERYEFF = 0.5;
const double SUPEREFF = 2;

PokemonDecorator::PokemonDecorator(Pokemon* p): p{p} {}

PokemonDecorator::~PokemonDecorator() = default;

void PokemonDecorator::learn(std::unique_ptr<Move> m) {
    p->learn(std::move(m));
}

void PokemonDecorator::attack(Pokemon& poke) const {
    p->attack(poke);
}

bool PokemonDecorator::fainted() const {
    return p->fainted();
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
