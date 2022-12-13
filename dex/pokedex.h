#include <iostream>
#include <memory>

class Stats;
class DexImpl;

class Pokedex {
    std::unique_ptr<DexImpl> pimpl;
 public:
    Pokedex();
    ~Pokedex();

    void prettyDex();
    const Stats& getStats(std::string name) const;
    friend std::ostream& operator<<(std::ostream& out, const Pokedex& pd);
};
