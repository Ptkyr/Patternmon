#ifndef __POKEDEX_H__
#define __POKEDEX_H__

#include <iostream>
#include <memory>

class Pokemon;
class DexImpl;

class Pokedex {
    std::unique_ptr<DexImpl> pimpl;
 public:
    Pokedex();
    ~Pokedex();

    void prettyDex();
    void print(const std::string& name) const;

    // returns a Pokemon with all its stats, typing
    //  based on info/pokedex.csv
    std::unique_ptr<Pokemon> spawn(const std::string& name) const;
};

#endif
