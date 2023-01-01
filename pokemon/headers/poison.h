#ifndef __POISON_H__
#define __POISON_H__

#include "pokdec.h"

class Poison: public PokemonDecorator {
public:
    Poison(Pokemon* ptr);

    void hitBy(GrassMove& fm, const double mult = 1) override;
    void hitBy(FightingMove& fm, const double mult = 1) override;
    void hitBy(PoisonMove& fm, const double mult = 1) override;
    void hitBy(GroundMove& fm, const double mult = 1) override;
    void hitBy(PsychicMove& fm, const double mult = 1) override;
    void hitBy(BugMove& fm, const double mult = 1) override;
    void hitBy(FairyMove& fm, const double mult = 1) override;
};

#endif
