#include "types.h"
#include "exceptions.h"
#include "termcodes.h"
#include "pokemon.h"
#include <map>

static const std::map<std::string, std::string> colours {
    {"NormalMove", Termcode::NORMAL},
    {"FireMove", Termcode::FIRE},
    {"WaterMove", Termcode::WATER},
    {"GrassMove", Termcode::GRASS},
    {"ElectricMove", Termcode::ELECTRIC},
    {"IceMove", Termcode::ICE},
    {"FightingMove", Termcode::FIGHTING},
    {"PoisonMove", Termcode::POISON},
    {"GroundMove", Termcode::GROUND},
    {"FlyingMove", Termcode::FLYING},
    {"PsychicMove", Termcode::PSYCHIC},
    {"BugMove", Termcode::BUG},
    {"RockMove", Termcode::ROCK},
    {"GhostMove", Termcode::GHOST},
    {"DragonMove", Termcode::DRAGON},
    {"DarkMove", Termcode::DARK},
    {"SteelMove", Termcode::STEEL},
    {"FairyMove", Termcode::FAIRY}
};

#define MKTYPESPEC(T) \
T::T(std::string s, Category c, int b, int a, int p) : Move(s, c, b, a, p) {} \
\
void T::hit(Pokemon& poke) { \
    poke.hitBy(*this); \
} \
\
std::string T::getName() const { \
    return name; \
} \
\
std::string T::getColour() const { \
    return colours.at(#T); \
}

MKTYPESPEC(NormalMove);
MKTYPESPEC(FireMove);
MKTYPESPEC(WaterMove);
MKTYPESPEC(GrassMove);
MKTYPESPEC(ElectricMove);
MKTYPESPEC(IceMove);
MKTYPESPEC(FightingMove);
MKTYPESPEC(PoisonMove);
MKTYPESPEC(GroundMove);
MKTYPESPEC(FlyingMove);
MKTYPESPEC(PsychicMove);
MKTYPESPEC(BugMove);
MKTYPESPEC(RockMove);
MKTYPESPEC(GhostMove);
MKTYPESPEC(DragonMove);
MKTYPESPEC(DarkMove);
MKTYPESPEC(SteelMove);
MKTYPESPEC(FairyMove);
