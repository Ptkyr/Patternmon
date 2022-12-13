#include "stats.h"
#include <vector>

Stats::Stats(int hp, int atk, int def, int spatk, int spdef, int spe): 
    hp{hp}, atk{atk}, def{def}, spatk{spatk}, spdef{spdef}, spe{spe} {}

int Stats::operator[](const int& x) const {
    const std::vector<int> tmp{hp, atk, def, spatk, spdef, spe};
    return tmp.at(x);
}
