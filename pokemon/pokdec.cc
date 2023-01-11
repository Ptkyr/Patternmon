#include "pokdec.h"
#include "move.h"
#include <utility>

const double IMMUNITY = 0;
const double NVERYEFF = 0.5;
const double SUPEREFF = 2;

PokemonDecorator::PokemonDecorator(Pokemon* ptr): p{ptr} {}

PokemonDecorator::~PokemonDecorator() = default;

void PokemonDecorator::learn(std::unique_ptr<Move> m) {
    p->learn(std::move(m));
}

bool PokemonDecorator::fainted() const {
    return p->fainted();
}

Move* PokemonDecorator::getMove(const size_t x) const {
    return p->getMove(x);
}

size_t PokemonDecorator::moveCount() const {
    return p->moveCount();
}

std::string PokemonDecorator::getName() const {
    return p->getName();
}

Stats& PokemonDecorator::getStats() {
    return p->getStats();
}

int PokemonDecorator::HP() const {
    return p->HP();
}

int PokemonDecorator::maxHP() const {
    return p->maxHP();
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
