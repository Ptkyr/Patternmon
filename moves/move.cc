#include "move.h"
#include "types.h"
#include "pokemon.h"
#include "exceptions.h"
#include <map>
#include <algorithm>
#include <cctype>
#include <functional>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

Move::Move(std::string n, Category c, int base, int acc, int pp): 
    name{n}, cat{c}, bp{base}, acc{acc}, pp{pp} {}

Move::~Move() = default;

int Move::getBP() const {
    return bp;
}

int Move::getAcc() const {
    return acc;
}

int Move::getPP() const {
    return pp;
}

Category Move::getPS() const {
    return cat;
}

std::string Move::getName() const {
    return name;
}

void Move::use() {
    --pp;
}

// Helper to ensure the return type is correct:
//  plain old std::make_unique probably doesn't work
template<typename T>
std::unique_ptr<Move> typeHelper(std::string s, Category c, int bp, int acc, int pp) {
    return std::make_unique<T>(s, c, bp, acc, pp);
}

static const std::map<
             int, 
             std::function<std::unique_ptr<Move>(std::string, Category, int, int, int)>
    > typeConverter {
    {1, typeHelper<NormalMove>},
    {2, typeHelper<FightingMove>},
    {3, typeHelper<FlyingMove>},
    {4, typeHelper<PoisonMove>},
    {5, typeHelper<GroundMove>},
    {6, typeHelper<RockMove>},
    {7, typeHelper<BugMove>},
    {8, typeHelper<GhostMove>},
    {9, typeHelper<SteelMove>},
    {10, typeHelper<FireMove>},
    {11, typeHelper<WaterMove>},
    {12, typeHelper<GrassMove>},
    {13, typeHelper<ElectricMove>},
    {14, typeHelper<PsychicMove>},
    {15, typeHelper<IceMove>},
    {16, typeHelper<DragonMove>},
    {17, typeHelper<DarkMove>},
    {18, typeHelper<FairyMove>}
};

std::unique_ptr<Move> makeMove(const std::string name) {
    const std::string infofrom = "movedata.csv";
    std::ifstream input{"./info/" + infofrom};
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
            // Miserable hacks
            if (s == "") {
                if (i == 2) s = "0"; // base power
                if (i == 4) s = "101"; // never-miss
            }
            entries.emplace_back(stoi(s));
        }
        const int bp = entries[2];
        const int pp = entries[3];
        const int acc = entries[4];
        const int move_kind = entries[7];
        Category c = Category::Physical;
        if (move_kind == 3) c = Category::Special;
        return typeConverter.at(entries[1])(name, c, bp, acc, pp);
    }
    throw ReadError{infofrom};
}
