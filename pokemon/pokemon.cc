#include "pokemon.h"
#include "move.h"
#include "pokedex.h"

std::unique_ptr<Pokemon> Pokemon::spawn(std::istream& in) {
    Pokedex dex;
    std::string name;
    std::getline(in, name, '@');
    name.pop_back();
    auto tmp = dex.spawn(name);
    std::string buffer;
    while (getline(in, buffer)) {
        if (buffer == "") break;
        if (buffer[0] == '-') {
            buffer.pop_back();
            buffer.pop_back();
            tmp->learn(makeMove(buffer.substr(2)));
        }
    }
    return tmp;
}
