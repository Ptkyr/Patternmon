#ifndef __POKEMONDECORATOR_H__
#define __POKEMONDECORATOR_H__

#include "pokemon.h"
#include <memory>

extern const double IMMUNITY;
extern const double NVERYEFF;
extern const double SUPEREFF;

class PokemonDecorator: public Pokemon {
protected:
    std::unique_ptr<Pokemon> p;
public:
    PokemonDecorator(Pokemon* ptr);
    virtual ~PokemonDecorator() = 0;

    void learn(std::unique_ptr<Move> m) override;
    void attack(Pokemon& p) const override;

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
