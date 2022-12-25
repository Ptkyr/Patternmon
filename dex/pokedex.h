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
    std::unique_ptr<Pokemon> spawn(const std::string& name) const;
    void print(const std::string& name) const;
};

#endif
