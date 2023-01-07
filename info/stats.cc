#include "stats.h"
#include "exceptions.h"
#include <vector>

Stats::Boost& Stats::Boost::Boost::operator++() {
    if (stage >= 6) throw TooBoosted{};
    ++stage;
    return *this;
}

Stats::Boost& Stats::Boost::Boost::operator--() {
    if (stage <= -6) throw TooBoosted{};
    --stage;
    return *this;
}

double Stats::Boost::Boost::operator()() const {
    if (stage >= 0) {
        return (static_cast<double>(stage + 2)) / 2.0;
    } else {
        return 2.0 / (static_cast<double>(2 - stage));
    }
}

void Stats::Boost::Boost::operator*() {
    stage = 0;
}

Stats::Stats(int h, int a, int d, int spa, int spd, int speed): 
    hp{h}, atk{a, Boost{}}, def{d, Boost{}}, 
    spatk{spa, Boost{}}, spdef{spd, Boost{}}, spe{speed, Boost{}} {}

int Stats::HP() const {
    return hp;
}

int Stats::ATK() const {
    return atk.first * atk.second();
}

int Stats::DEF() const {
    return def.first * def.second();
}

int Stats::SPATK() const {
    return spatk.first * spatk.second();
}

int Stats::SPDEF() const {
    return spdef.first * spdef.second();
}

int Stats::SPE() const {
    return spe.first * spe.second();
}

int Stats::operator[](const int& x) const {
    const std::vector<int> tmp{hp, atk.first, def.first, 
                               spatk.first, spdef.first, spe.first};
    return tmp.at(static_cast<size_t>(x));
}
