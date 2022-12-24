#ifndef __DEXIMPL_H__
#define __DEXIMPL_H__
#include "stats.h"
#include <map>
#include <vector>
#include <string>

class DexImpl {
  protected:
    const std::map<std::string, Stats> dex{
        {"Necrozma-Dusk Mane", {97, 157, 127, 113, 109, 77}},
        {"Minccino", {55, 50, 40, 40, 40, 75}},
        {"Landorus", {89, 125, 90, 115, 80, 101}},
        {"Timburr", {75, 80, 55, 25, 35, 35}},
        {"Regieleki", {80, 100, 50, 100, 50, 200}},
        {"Liepard", {64, 88, 50, 88, 50, 106}},
        {"Trubbish", {50, 50, 62, 40, 62, 65}},
        {"Gothita", {45, 30, 50, 55, 65, 45}},
        {"Herdier", {65, 80, 65, 35, 65, 60}},
        {"Vanillite", {36, 50, 50, 65, 60, 44}}
    };
    const std::vector<std::string> statNames{"HP", "ATK", "DEF", "SPATK", "SPDEF", "SPE"};
  public:
    virtual void print() const = 0;
    const Stats& getStats(std::string name) const;
    virtual ~DexImpl() = default;
};

#endif
