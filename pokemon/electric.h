#ifndef __ELECTRIC_H__
#define __ELECTRIC_H__

#include "pokdec.h"

class Electric: public PokemonDecorator {
public:
    Electric(Pokemon* p);

    void hitBy(ElectricMove& gm, const double mult = 1) override;
    void hitBy(GroundMove& gm, const double mult = 1) override;
    void hitBy(FlyingMove& gm, const double mult = 1) override;
};

#endif
