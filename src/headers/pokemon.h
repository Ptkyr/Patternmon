#ifndef __POKEMON_H__
#define __POKEMON_H__

#include "stats.h"
#include <string>
#include <vector>
#include <iostream>

class Move;
class WaterMove;
class FireMove;
class GrassMove;
class ElectricMove;

class Pokemon {
protected:
    std::string name;
    Stats stats;
    std::vector<Move*> moves;
    int level = 100;
    int hp;
    const int max_hp;

    void forget(Move* m, const int n);
public:
    Pokemon(const std::string& n, Stats s);
    virtual ~Pokemon() = 0;

    virtual void hitBy(WaterMove& wm, const double mult = 1) = 0;
    virtual void hitBy(FireMove& fm, const double mult = 1) = 0;
    virtual void hitBy(GrassMove& gm, const double mult = 1) = 0;
    virtual void hitBy(ElectricMove& gm, const double mult = 1) = 0;

    void learn(Move* m);
    void attack(Pokemon& p) const;
};

#endif
