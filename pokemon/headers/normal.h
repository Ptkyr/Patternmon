#ifndef __NORMAL_H__
#define __NORMAL_H__

#include "pokdec.h"

class Normal: public PokemonDecorator {
public:
    Normal(Pokemon* p);

    void hitBy(FightingMove& wm, const double mult = 1) override;
    void hitBy(GhostMove& wm, const double mult = 1) override;
};

#endif
