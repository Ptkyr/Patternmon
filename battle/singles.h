#ifndef __SINGLES_H__
#define __SINGLES_H__

#include "battle.h"

class Trainer;
class Pokemon;

class Singles: public Battle {
    // These swap after each half-turn
    Trainer* you;
    Trainer* foe;
    Pokemon* cur;
    Pokemon* opp;

    void initialMessage() override;
    void turn() override;
    void endMessage() override;
public:
    Singles(Trainer* x, Trainer* y);
};

#endif
