#ifndef __PSYCHIC_H__
#define __PSYCHIC_H__

#include "pokdec.h"

class Psychic: public PokemonDecorator {
public:
    Psychic(Pokemon* p);

    void hitBy(FightingMove& fm, const double mult = 1) override;
    void hitBy(PsychicMove& fm, const double mult = 1) override;
    void hitBy(BugMove& fm, const double mult = 1) override;
    void hitBy(GhostMove& fm, const double mult = 1) override;
    void hitBy(DarkMove& fm, const double mult = 1) override;
};

#endif
