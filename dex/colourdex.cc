#include "colourdex.h"
#include <iomanip>
#include "termcodes.h"

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

void ColourDex::print() const {
    for (const auto& mon: dex) {
        out << mon.first << " has the following stats:" << std::endl;
        for (int i = 0; i < 6; ++i) {
            out << "     " << std::setw(7) << (statNames[i] + ": "); 
            colourNumber(mon.second[i]);
            out << std::endl;
        }
    }
}
