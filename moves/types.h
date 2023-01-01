#ifndef __TYPES_H__
#define __TYPES_H__

#include "move.h"
#include <memory>
#include <map>
#include <string>

#define MKTYPEDECL(T) \
class T: public Move { \
public: \
    T(std::string n, Category c, int bp, int acc, int pp); \
    void hit(Pokemon& p) override; \
    std::string getName() const override; \
}

MKTYPEDECL(NormalMove);
MKTYPEDECL(FireMove);
MKTYPEDECL(WaterMove);
MKTYPEDECL(GrassMove);
MKTYPEDECL(ElectricMove);
MKTYPEDECL(IceMove);
MKTYPEDECL(FightingMove);
MKTYPEDECL(PoisonMove);
MKTYPEDECL(GroundMove);
MKTYPEDECL(FlyingMove);
MKTYPEDECL(PsychicMove);
MKTYPEDECL(BugMove);
MKTYPEDECL(RockMove);
MKTYPEDECL(GhostMove);
MKTYPEDECL(DragonMove);
MKTYPEDECL(DarkMove);
MKTYPEDECL(SteelMove);
MKTYPEDECL(FairyMove);

template<typename T>
void addType(std::unique_ptr<Pokemon>& p) {
    p = std::make_unique<T>(p.release());
}

template<typename... Ts>
void addType(auto&& p) {
    auto f = [&]<typename T> {
        addType<T>(p);
    };
    (f.template operator()<Ts>(), ...);
}

#endif
