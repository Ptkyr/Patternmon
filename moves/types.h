#ifndef __TYPES_H__
#define __TYPES_H__

#include "move.h"
#include "termcodes.h"
#include <iostream>

class NormalMove: public Move {
public:
    NormalMove(std::string n, Category c, int bp, int pp) : Move(n, c, bp, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::NORMAL + name + Termcode::RESET;
    }
};

class WaterMove: public Move {
public:
    WaterMove(std::string n, Category c, int bp, int pp) : Move(n, c, bp, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::WATER + name + Termcode::RESET;
    }
};

class FireMove: public Move {
public:
    FireMove(std::string n, Category c, int bp, int pp) : Move(n, c, bp, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::FIRE + name + Termcode::RESET;
    }
};

class GrassMove: public Move {
public:
    GrassMove(std::string n, Category c, int bp, int pp) : Move(n, c, bp, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::GRASS + name + Termcode::RESET;
    }
};

class ElectricMove: public Move {
public:
    ElectricMove(std::string n, Category c, int bp, int pp) : Move(n, c, bp, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::ELECTRIC + name + Termcode::RESET;
    }
};

class IceMove: public Move {
public:
    IceMove(std::string n, Category c, int bp, int pp) : Move(n, c, bp, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::ICE + name + Termcode::RESET;
    }
};

class FightingMove: public Move {
public:
    FightingMove(std::string n, Category c, int bp, int pp) : Move(n, c, bp, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::FIGHTING + name + Termcode::RESET;
    }
};

class PoisonMove: public Move {
public:
    PoisonMove(std::string n, Category c, int bp, int pp) : Move(n, c, bp, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::POISON + name + Termcode::RESET;
    }
};

class GroundMove: public Move {
public:
    GroundMove(std::string n, Category c, int bp, int pp) : Move(n, c, bp, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::GROUND + name + Termcode::RESET;
    }
};

class FlyingMove: public Move {
public:
    FlyingMove(std::string n, Category c, int bp, int pp) : Move(n, c, bp, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::FLYING + name + Termcode::RESET;
    }
};

class PsychicMove: public Move {
public:
    PsychicMove(std::string n, Category c, int bp, int pp) : Move(n, c, bp, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::PSYCHIC + name + Termcode::RESET;
    }
};

class BugMove: public Move {
public:
    BugMove(std::string n, Category c, int bp, int pp) : Move(n, c, bp, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::BUG + name + Termcode::RESET;
    }
};

class RockMove: public Move {
public:
    RockMove(std::string n, Category c, int bp, int pp) : Move(n, c, bp, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::ROCK + name + Termcode::RESET;
    }
};

class GhostMove: public Move {
public:
    GhostMove(std::string n, Category c, int bp, int pp) : Move(n, c, bp, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::GHOST + name + Termcode::RESET;
    }
};

class DragonMove: public Move {
public:
    DragonMove(std::string n, Category c, int bp, int pp) : Move(n, c, bp, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::DRAGON + name + Termcode::RESET;
    }
};

class DarkMove: public Move {
public:
    DarkMove(std::string n, Category c, int bp, int pp) : Move(n, c, bp, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::DARK + name + Termcode::RESET;
    }
};

class SteelMove: public Move {
public:
    SteelMove(std::string n, Category c, int bp, int pp) : Move(n, c, bp, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::STEEL + name + Termcode::RESET;
    }
};

class FairyMove: public Move {
public:
    FairyMove(std::string n, Category c, int bp, int pp) : Move(n, c, bp, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::FAIRY + name + Termcode::RESET;
    }
};

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
