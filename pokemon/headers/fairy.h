#ifndef __FAIRY_H__
#define __FAIRY_H__

#include "pokdec.h"

class Fairy: public PokemonDecorator {
public:
    Fairy(Pokemon* ptr);

    void hitBy(FightingMove& gm, const double mult = 1) override;
    void hitBy(PoisonMove& gm, const double mult = 1) override;
    void hitBy(BugMove& gm, const double mult = 1) override;
    void hitBy(DragonMove& gm, const double mult = 1) override;
    void hitBy(DarkMove& gm, const double mult = 1) override;
    void hitBy(SteelMove& gm, const double mult = 1) override;
};

#endif
