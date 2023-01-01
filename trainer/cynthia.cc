#include "cynthia.h"
#include "pokemon.h"
#include "move.h"
#include <fstream>

Cynthia::Cynthia(): Trainer("Cynthia") {
    std::ifstream cyn_team{"./teamfiles/cynthia.txt"};
    cyn_team >> *this;
}
