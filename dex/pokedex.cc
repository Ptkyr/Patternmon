#include "pokedex.h"
#include "deximpl.h"
#include "basicdex.h"
#include "colourdex.h"

Pokedex::Pokedex(): pimpl{std::make_unique<BasicDex>()} {}

Pokedex::~Pokedex() = default;

void Pokedex::prettyDex() {
    pimpl = std::make_unique<ColourDex>();
}

const Stats& Pokedex::getStats(std::string name) const {
    return pimpl->getStats(name);
}

std::ostream& operator<<(std::ostream& out, const Pokedex& pd) {
    pd.pimpl->print();
    return out;
}
