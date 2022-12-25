#include "basicdex.h"
#include <iomanip>
#include <fstream>
#include <sstream>

void BasicDex::print(const std::string& name) const {
    std::ifstream input{"./dex/pokemon.txt"};
    std::string tmp;
    while (std::getline(input, tmp)) {
        std::istringstream iss{tmp};
        std::string s;
        std::vector<std::string> entries;
        std::getline(iss, s, ',');
        std::getline(iss, s, ',');
        if (s != name) continue;
        while (getline(iss, s, ',')) {
            entries.emplace_back(std::move(s));
        }
        out << name << " has the following stats:" << std::endl;
        for (int i = 0; i < 6; ++i) {
            out << "     " << std::setw(7) << (statNames[i] + ": ") << entries[i + 3] << std::endl;
        }
    }
}

BasicDex::~BasicDex() = default;
