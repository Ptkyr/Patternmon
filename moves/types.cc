#include "types.h"
#include "exceptions.h"
#include <map>
#include <algorithm>
#include <cctype>
#include <functional>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

template<typename T>
std::unique_ptr<Move> typeHelper(std::string s, Category c, int bp, int acc, int pp) {
    return std::make_unique<T>(s, c, bp, acc, pp);
}

static const std::map<int, 
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
        return typeConverter.at(entries[1])(name, c, bp, acc, pp);
    }
    throw SpawnError{};
}
