#ifndef __FIGHTING_H__
#define __FIGHTING_H__

#include "pokdec.h"

class Fighting: public PokemonDecorator {
public:
    Fighting(Pokemon* p);

    void hitBy(FlyingMove& fm, const double mult = 1) override;
    void hitBy(PsychicMove& fm, const double mult = 1) override;
    void hitBy(BugMove& fm, const double mult = 1) override;
    void hitBy(RockMove& fm, const double mult = 1) override;
    void hitBy(DarkMove& gm, const double mult = 1) override;
    void hitBy(FairyMove& gm, const double mult = 1) override;
};

#endif
