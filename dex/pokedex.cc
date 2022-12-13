#include "pokedex.h"
#include "termcodes.h"
#include "stats.h"
#include <map>
#include <vector>
#include <iomanip>

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

const Stats& DexImpl::getStats(std::string name) const {
    return dex.at(name);
}

class BasicDex: public DexImpl {
    std::ostream& out = std::cout;
  public:
    void print() const override {
        for (const auto& mon: dex) {
            out << mon.first << " has the following stats:" << std::endl;
            for (int i = 0; i < 6; ++i) {
                out << "     " << std::setw(7) << (statNames[i] + ": ") << mon.second[i] << std::endl;
            }
        }
    }
};

class ColourDex: public DexImpl {
    std::ostream& out = std::cout;
    void colourNumber(const int& n) const {
        if (n < 50) {
            out << RED;
        } else if (n < 70) {
            out << ORANGE;
        } else if (n < 100) {
            out << YELLOW;
        } else if (n < 120) {
            out << YELLOWGREEN;
        } else if (n < 160) {
            out << GREEN;
        } else {
            out << TEAL;
        }
        out << n << RESET;
    }
  public:
    void print() const override {
        for (const auto& mon: dex) {
            out << mon.first << " has the following stats:" << std::endl;
            for (int i = 0; i < 6; ++i) {
                out << "     " << std::setw(7) << (statNames[i] + ": "); 
                colourNumber(mon.second[i]);
                out << std::endl;
            }
        }
    }
};

// Actual Pokedex methods here
Pokedex::Pokedex(): pimpl{std::make_unique<BasicDex>()} {}

Pokedex::~Pokedex() = default;

void Pokedex::prettyDex() {
    pimpl = std::make_unique<ColourDex>();
}

const Stats& Pokedex::getStats(std::string name) const {
    return pimpl->getStats(name);
}

std::ostream& operator<<(std::ostream& out, const Pokedex& pd) {
    pd.pimpl->print();
    return out;
}
