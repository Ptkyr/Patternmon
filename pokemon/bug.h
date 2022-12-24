#ifndef __BUG_H__
#define __BUG_H__

#include "pokdec.h"

class Bug: public PokemonDecorator {
public:
    Bug(Pokemon* p);

    void hitBy(FireMove& fm, const double mult = 1) override;
    void hitBy(GrassMove& gm, const double mult = 1) override;
    void hitBy(FightingMove& gm, const double mult = 1) override;
    void hitBy(GroundMove& gm, const double mult = 1) override;
    void hitBy(FlyingMove& gm, const double mult = 1) override;
    void hitBy(RockMove& gm, const double mult = 1) override;
};

#endif
