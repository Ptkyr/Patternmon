#ifndef __ICE_H__
#define __ICE_H__

#include "pokdec.h"

class Ice: public PokemonDecorator {
public:
    Ice(Pokemon* ptr);

    void hitBy(FireMove& fm, const double mult = 1) override;
    void hitBy(IceMove& gm, const double mult = 1) override;
    void hitBy(FightingMove& gm, const double mult = 1) override;
    void hitBy(RockMove& gm, const double mult = 1) override;
    void hitBy(SteelMove& gm, const double mult = 1) override;
};

#endif
