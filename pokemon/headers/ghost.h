#ifndef __GHOST_H__
#define __GHOST_H__

#include "pokdec.h"

class Ghost: public PokemonDecorator {
public:
    Ghost(Pokemon* ptr);

    void hitBy(NormalMove& fm, const double mult = 1) override;
    void hitBy(FightingMove& gm, const double mult = 1) override;
    void hitBy(PoisonMove& gm, const double mult = 1) override;
    void hitBy(BugMove& gm, const double mult = 1) override;
    void hitBy(GhostMove& gm, const double mult = 1) override;
    void hitBy(DarkMove& gm, const double mult = 1) override;
};

#endif
