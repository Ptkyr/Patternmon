#include "colourdex.h"
#include "termcodes.h"
#include <iomanip>
#include <fstream>
#include <sstream>

void ColourDex::colourNumber(const int& n) const {
    if (n < 50) {
        out << Termcode::RED;
    } else if (n < 70) {
        out << Termcode::ORANGE;
    } else if (n < 100) {
        out << Termcode::YELLOW;
    } else if (n < 120) {
        out << Termcode::YELLOWGREEN;
    } else if (n < 160) {
        out << Termcode::GREEN;
    } else {
        out << Termcode::TEAL;
    }
    out << n << Termcode::RESET;
}

void ColourDex::print(const std::string& name) const {
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
        for (size_t i = 0; i < 6; ++i) {
            out << "     " << std::setw(7) << (statNames[i] + ": "); 
            colourNumber(stoi(entries[i + 3]));
            out << std::endl;
        }
    }
}

ColourDex::~ColourDex() = default;
