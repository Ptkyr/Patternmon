#ifndef __TYPES_H__
#define __TYPES_H__

#include "move.h"
#include "termcodes.h"
#include "exceptions.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

class NormalMove: public Move {
public:
    NormalMove(std::string n, Category c, int bp, int acc, int pp) : Move(n, c, bp, acc, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::NORMAL + name + Termcode::RESET;
    }
};

class WaterMove: public Move {
public:
    WaterMove(std::string n, Category c, int bp, int acc, int pp) : Move(n, c, bp, acc, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::WATER + name + Termcode::RESET;
    }
};

class FireMove: public Move {
public:
    FireMove(std::string n, Category c, int bp, int acc, int pp) : Move(n, c, bp, acc, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::FIRE + name + Termcode::RESET;
    }
};

class GrassMove: public Move {
public:
    GrassMove(std::string n, Category c, int bp, int acc, int pp) : Move(n, c, bp, acc, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::GRASS + name + Termcode::RESET;
    }
};

class ElectricMove: public Move {
public:
    ElectricMove(std::string n, Category c, int bp, int acc, int pp) : Move(n, c, bp, acc, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::ELECTRIC + name + Termcode::RESET;
    }
};

class IceMove: public Move {
public:
    IceMove(std::string n, Category c, int bp, int acc, int pp) : Move(n, c, bp, acc, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::ICE + name + Termcode::RESET;
    }
};

class FightingMove: public Move {
public:
    FightingMove(std::string n, Category c, int bp, int acc, int pp) : Move(n, c, bp, acc, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::FIGHTING + name + Termcode::RESET;
    }
};

class PoisonMove: public Move {
public:
    PoisonMove(std::string n, Category c, int bp, int acc, int pp) : Move(n, c, bp, acc, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::POISON + name + Termcode::RESET;
    }
};

class GroundMove: public Move {
public:
    GroundMove(std::string n, Category c, int bp, int acc, int pp) : Move(n, c, bp, acc, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::GROUND + name + Termcode::RESET;
    }
};

class FlyingMove: public Move {
public:
    FlyingMove(std::string n, Category c, int bp, int acc, int pp) : Move(n, c, bp, acc, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::FLYING + name + Termcode::RESET;
    }
};

class PsychicMove: public Move {
public:
    PsychicMove(std::string n, Category c, int bp, int acc, int pp) : Move(n, c, bp, acc, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::PSYCHIC + name + Termcode::RESET;
    }
};

class BugMove: public Move {
public:
    BugMove(std::string n, Category c, int bp, int acc, int pp) : Move(n, c, bp, acc, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::BUG + name + Termcode::RESET;
    }
};

class RockMove: public Move {
public:
    RockMove(std::string n, Category c, int bp, int acc, int pp) : Move(n, c, bp, acc, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::ROCK + name + Termcode::RESET;
    }
};

class GhostMove: public Move {
public:
    GhostMove(std::string n, Category c, int bp, int acc, int pp) : Move(n, c, bp, acc, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::GHOST + name + Termcode::RESET;
    }
};

class DragonMove: public Move {
public:
    DragonMove(std::string n, Category c, int bp, int acc, int pp) : Move(n, c, bp, acc, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::DRAGON + name + Termcode::RESET;
    }
};

class DarkMove: public Move {
public:
    DarkMove(std::string n, Category c, int bp, int acc, int pp) : Move(n, c, bp, acc, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::DARK + name + Termcode::RESET;
    }
};

class SteelMove: public Move {
public:
    SteelMove(std::string n, Category c, int bp, int acc, int pp) : Move(n, c, bp, acc, pp) {}
    void hit(Pokemon& p) override {
        p.hitBy(*this);
    }
    std::string getName() const override {
        return Termcode::STEEL + name + Termcode::RESET;
    }
};

class FairyMove: public Move {
public:
    FairyMove(std::string n, Category c, int bp, int acc, int pp) : Move(n, c, bp, acc, pp) {}
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

template<typename T>
std::unique_ptr<Move> makeMove(const std::string name) {
    std::ifstream input{"./info/movedata.csv"};
    std::string tmp;
    while (std::getline(input, tmp)) {
        std::istringstream iss{tmp};
        std::string s;
        std::getline(iss, s, ',');
        std::getline(iss, s, ',');
        // Make formatting compatible with csv file
        auto conv = [](const char c){
            if (c == ' ') return '-';
            return static_cast<char>(std::tolower(c));
        };
        std::string copy = name;
        std::transform(copy.begin(), copy.end(), copy.begin(), conv);
        if (s != copy) continue;
        std::vector<int> entries;
        for (int i = 0; i < 8; ++i) {
            getline(iss, s, ',');
            // Miserable hack to account for never-miss moves
            if (s == "" && i == 4) s = "101";
            entries.emplace_back(stoi(s));
        }
        const int bp = entries[2];
        const int pp = entries[3];
        const int acc = entries[4];
        const int move_kind = entries[7];
        Category c = Category::Physical;
        if (move_kind == 3) c = Category::Special;
        return std::make_unique<T>(name, c, bp, acc, pp);
    }
    throw SpawnError{};
}

#endif
