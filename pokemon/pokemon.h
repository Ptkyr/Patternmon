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
class NormalMove;
class IceMove;
class FightingMove;
class PoisonMove;
class FlyingMove;
class PsychicMove;
class BugMove;
class RockMove;
class GhostMove;
class DragonMove;
class DarkMove;
class SteelMove;
class FairyMove;

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

    virtual void hitBy(NormalMove& gm, const double mult = 1) = 0;
    virtual void hitBy(FireMove& fm, const double mult = 1) = 0;
    virtual void hitBy(WaterMove& wm, const double mult = 1) = 0;
    virtual void hitBy(GrassMove& gm, const double mult = 1) = 0;
    virtual void hitBy(ElectricMove& em, const double mult = 1) = 0;
    virtual void hitBy(IceMove& gm, const double mult = 1) = 0;
    virtual void hitBy(FightingMove& gm, const double mult = 1) = 0;
    virtual void hitBy(PoisonMove& gm, const double mult = 1) = 0;
    virtual void hitBy(GroundMove& gm, const double mult = 1) = 0;
    virtual void hitBy(FlyingMove& gm, const double mult = 1) = 0;
    virtual void hitBy(PsychicMove& gm, const double mult = 1) = 0;
    virtual void hitBy(BugMove& gm, const double mult = 1) = 0;
    virtual void hitBy(RockMove& gm, const double mult = 1) = 0;

    void learn(std::shared_ptr<Move> m);
    void attack(Pokemon& p) const;
};

template<typename T>
void addType(std::unique_ptr<Pokemon>& p) {
    p = std::make_unique<T>(p.release());
}

#endif
