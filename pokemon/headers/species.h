#ifndef __SPECIES_H__
#define __SPECIES_H__

#include "pokemon.h"
#include "stats.h"
#include <string>
#include <vector>

class Move;

class Species: public Pokemon {
    std::string name;
    Stats stats;
    std::vector<std::unique_ptr<Move>> moves;
    int level = 100;
    int hp;
    const int max_hp;

    void accuracyCheck(const Move& m) const;
    void printHit(const double mult) const;
    void calcDamage(Move& m, const double mult);
    void helpHit(Move& m, const double mult);
public:
    Species(const std::string& name, Stats s);
    ~Species();

    void learn(std::unique_ptr<Move> m) override;
    void attack(Pokemon& p) const override;
    Move* getMove(const size_t x = 0) const override; 
    size_t moveCount() const override;
    std::string getName() const override;

    bool fainted() const override;

    void hitBy(NormalMove& gm, const double mult = 1) override;
    void hitBy(FireMove& fm, const double mult = 1) override;
    void hitBy(WaterMove& wm, const double mult = 1) override;
    void hitBy(GrassMove& gm, const double mult = 1) override;
    void hitBy(ElectricMove& gm, const double mult = 1) override;
    void hitBy(IceMove& gm, const double mult = 1) override;
    void hitBy(FightingMove& gm, const double mult = 1) override;
    void hitBy(PoisonMove& gm, const double mult = 1) override;
    void hitBy(GroundMove& gm, const double mult = 1) override;
    void hitBy(FlyingMove& gm, const double mult = 1) override;
    void hitBy(PsychicMove& gm, const double mult = 1) override;
    void hitBy(BugMove& gm, const double mult = 1) override;
    void hitBy(RockMove& gm, const double mult = 1) override;
    void hitBy(GhostMove& gm, const double mult = 1) override;
    void hitBy(DragonMove& gm, const double mult = 1) override;
    void hitBy(DarkMove& gm, const double mult = 1) override;
    void hitBy(SteelMove& gm, const double mult = 1) override;
    void hitBy(FairyMove& gm, const double mult = 1) override;
};

#endif
