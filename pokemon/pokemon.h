#ifndef __POKEMON_H__
#define __POKEMON_H__

#include "stats.h"
#include <string>
#include <vector>
#include <iostream>
#include <memory>

class Move;
class WaterMove;
class FireMove;
class GrassMove;
class ElectricMove;
class GroundMove;

class Pokemon {
protected:
    std::string name;
    Stats stats;
    std::vector<std::shared_ptr<Move>> moves;
    int level = 100;
    int hp;
    const int max_hp;

public:
    Pokemon(const std::string& n, Stats s);
    virtual ~Pokemon() = 0;

    virtual void hitBy(WaterMove& wm, const double mult = 1) = 0;
    virtual void hitBy(FireMove& fm, const double mult = 1) = 0;
    virtual void hitBy(GrassMove& gm, const double mult = 1) = 0;
    virtual void hitBy(ElectricMove& em, const double mult = 1) = 0;
    virtual void hitBy(GroundMove& gm, const double mult = 1) = 0;

    void learn(std::shared_ptr<Move> m);
    void attack(Pokemon& p) const;
};

#endif
