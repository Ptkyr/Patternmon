#ifndef __FIRE_H__
#define __FIRE_H__

#include "pokdec.h"

class Fire: public PokemonDecorator {
public:
    Fire(Pokemon* p);

    void hitBy(WaterMove& wm, const double mult = 1) override;
    void hitBy(FireMove& fm, const double mult = 1) override;
    void hitBy(GrassMove& gm, const double mult = 1) override;
    void hitBy(GroundMove& gm, const double mult = 1) override;
    void hitBy(IceMove& gm, const double mult = 1) override;
    void hitBy(BugMove& gm, const double mult = 1) override;
    void hitBy(RockMove& gm, const double mult = 1) override;
};

#endif
