#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "trainer.h"

class Player: public Trainer {
public:
    Player(const std::string& s);

    Move* getMove() const override;
    void switchOut() override;
};

#endif
