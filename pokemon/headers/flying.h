#ifndef __FLYING_H__
#define __FLYING_H__

#include "pokdec.h"

class Flying: public PokemonDecorator {
public:
    Flying(Pokemon* p);

    void hitBy(GrassMove& gm, const double mult = 1) override;
    void hitBy(ElectricMove& gm, const double mult = 1) override;
    void hitBy(IceMove& gm, const double mult = 1) override;
    void hitBy(FightingMove& gm, const double mult = 1) override;
    void hitBy(GroundMove& gm, const double mult = 1) override;
    void hitBy(BugMove& gm, const double mult = 1) override;
    void hitBy(RockMove& gm, const double mult = 1) override;
};

#endif
