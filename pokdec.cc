#include "pokdec.h"
#include <utility>

PokemonDecorator::PokemonDecorator(Pokemon* p): Pokemon{*p}, p{p} {}

PokemonDecorator::~PokemonDecorator() {
    delete p;
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
