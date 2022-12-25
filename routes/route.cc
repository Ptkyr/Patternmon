#include "route.h"
#include "species.h"
#include "pokedex.h"
#include "exceptions.h"
#include <iostream>
#include <utility>
#include <random> // for RNG

Route::Route(std::vector<std::string> s, std::vector<double> c):
    spawns{std::move(s)}, chances{std::move(c)} {}

Route::~Route() = default;

std::unique_ptr<Pokemon> Route::spawn() {
    Pokedex dex;
    std::random_device rd;
    std::mt19937 gen{rd()};
    std::uniform_int_distribution<> dist{1, 100};
    // generate a pseudo-random int between 1 and 100, inclusive
    const int index = dist(gen);
    int i = 0;
    for (const auto& chance: chances) {
        if (index <= chance) {
            return dex.spawn(spawns[i]);
        }
        ++i;
    }
    throw SpawnError{};
}
