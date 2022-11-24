#ifndef __SPECIES_H__
#define __SPECIES_H__

#include "pokemon.h"
#include <string>
class Move;

class Species: public Pokemon {
    void calcDamage(Move& m, const double mult);
    void printHit(const double mult) const;
public:
    Species(std::string name, Stats s);

    void hitBy(WaterMove& wm, const double mult = 1) override;
    void hitBy(FireMove& fm, const double mult = 1) override;
    void hitBy(GrassMove& gm, const double mult = 1) override;
    void hitBy(ElectricMove& gm, const double mult = 1) override;
};

#endif
