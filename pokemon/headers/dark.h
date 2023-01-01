#ifndef __DARK_H__
#define __DARK_H__

#include "pokdec.h"

class Dark: public PokemonDecorator {
public:
    Dark(Pokemon* ptr);

    void hitBy(FightingMove& fm, const double mult = 1) override;
    void hitBy(PsychicMove& fm, const double mult = 1) override;
    void hitBy(BugMove& fm, const double mult = 1) override;
    void hitBy(GhostMove& fm, const double mult = 1) override;
    void hitBy(DarkMove& fm, const double mult = 1) override;
    void hitBy(FairyMove& fm, const double mult = 1) override;
};

#endif
