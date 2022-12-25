#ifndef __GRASS_H__
#define __GRASS_H__

#include "pokdec.h"

class Grass: public PokemonDecorator {
public:
    Grass(Pokemon* p);

    void hitBy(FireMove& fm, const double mult = 1) override;
    void hitBy(WaterMove& wm, const double mult = 1) override;
    void hitBy(GrassMove& gm, const double mult = 1) override;
    void hitBy(ElectricMove& gm, const double mult = 1) override;
    void hitBy(IceMove& gm, const double mult = 1) override;
    void hitBy(PoisonMove& gm, const double mult = 1) override;
    void hitBy(GroundMove& gm, const double mult = 1) override;
    void hitBy(FlyingMove& gm, const double mult = 1) override;
    void hitBy(BugMove& gm, const double mult = 1) override;
};

#endif
