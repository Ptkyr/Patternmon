#ifndef __DRAGON_H__
#define __DRAGON_H__

#include "pokdec.h"

class Dragon: public PokemonDecorator {
public:
    Dragon(Pokemon* p);

    void hitBy(FireMove& fm, const double mult = 1) override;
    void hitBy(WaterMove& wm, const double mult = 1) override;
    void hitBy(GrassMove& gm, const double mult = 1) override;
    void hitBy(ElectricMove& gm, const double mult = 1) override;
    void hitBy(IceMove& gm, const double mult = 1) override;
    void hitBy(DragonMove& gm, const double mult = 1) override;
    void hitBy(FairyMove& gm, const double mult = 1) override;
};

#endif
