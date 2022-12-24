#include "basicdex.h"
#include <iomanip>

void BasicDex::print() const {
    for (const auto& mon: dex) {
        out << mon.first << " has the following stats:" << std::endl;
        for (int i = 0; i < 6; ++i) {
            out << "     " << std::setw(7) << (statNames[i] + ": ") << mon.second[i] << std::endl;
        }
    }
}
