#ifndef __POKEMON_H__
#define __POKEMON_H__

#include <memory>
#include "infotypes.h"

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
public:
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
    virtual void hitBy(GhostMove& gm, const double mult = 1) = 0;
    virtual void hitBy(DragonMove& gm, const double mult = 1) = 0;
    virtual void hitBy(DarkMove& gm, const double mult = 1) = 0;
    virtual void hitBy(SteelMove& gm, const double mult = 1) = 0;
    virtual void hitBy(FairyMove& gm, const double mult = 1) = 0;

    virtual void learn(std::unique_ptr<Move> m) = 0;
    virtual void attack(Pokemon& p) const = 0;
    virtual bool fainted() const = 0;

    virtual ~Pokemon() = default;
};

#endif
