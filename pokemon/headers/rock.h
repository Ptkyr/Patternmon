#ifndef __ROCK_H__
#define __ROCK_H__

#include "pokdec.h"

class Rock: public PokemonDecorator {
public:
    Rock(Pokemon* ptr);

    void hitBy(NormalMove& fm, const double mult = 1) override;
    void hitBy(FireMove& fm, const double mult = 1) override;
    void hitBy(WaterMove& wm, const double mult = 1) override;
    void hitBy(GrassMove& gm, const double mult = 1) override;
    void hitBy(FightingMove& gm, const double mult = 1) override;
    void hitBy(PoisonMove& gm, const double mult = 1) override;
    void hitBy(GroundMove& gm, const double mult = 1) override;
    void hitBy(FlyingMove& gm, const double mult = 1) override;
    void hitBy(SteelMove& gm, const double mult = 1) override;
};

#endif
