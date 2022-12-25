#include "pokedex.h"
#include "deximpl.h"
#include "basicdex.h"
#include "colourdex.h"
// this should not be necessary
#include "pokemon.h"

Pokedex::Pokedex(): pimpl{std::make_unique<BasicDex>()} {}

Pokedex::~Pokedex() = default;

void Pokedex::prettyDex() {
    pimpl = std::make_unique<ColourDex>();
}

std::unique_ptr<Pokemon> Pokedex::spawn(const std::string& name) const {
    return pimpl->spawn(name);
}

void Pokedex::print(const std::string& name) const {
    pimpl->print(name);
}
