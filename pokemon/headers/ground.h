#ifndef __GROUND_H__
#define __GROUND_H__

#include "pokdec.h"

class Ground: public PokemonDecorator {
public:
    Ground(Pokemon* ptr);

    void hitBy(WaterMove& wm, const double mult = 1) override;
    void hitBy(GrassMove& gm, const double mult = 1) override;
    void hitBy(ElectricMove& gm, const double mult = 1) override;
    void hitBy(IceMove& gm, const double mult = 1) override;
    void hitBy(PoisonMove& gm, const double mult = 1) override;
    void hitBy(RockMove& gm, const double mult = 1) override;
};

#endif
