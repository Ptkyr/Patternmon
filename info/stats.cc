#include "stats.h"
#include <vector>

Stats::Stats(int h, int a, int d, int spa, int spd, int speed): 
    hp{h}, atk{a}, def{d}, spatk{spa}, spdef{spd}, spe{speed} {}

int Stats::operator[](const int& x) const {
    const std::vector<int> tmp{hp, atk, def, spatk, spdef, spe};
    return tmp.at(static_cast<size_t>(x));
}
