#include "pokemon.h"
#include "move.h"
#include "pokedex.h"
#include "termcodes.h"
#include <iomanip>

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

std::ostream& operator<<(std::ostream& out, const Pokemon& p) {
    // Display all moves
    for (size_t i = 0; i < p.moveCount(); ++i) {
        const Move* tmp_move = p.getMove(i);
        if (i == 2) out << std::endl;
        // Exeedingly wide buffer due to termcodes
        out << tmp_move->getColour();
        out << std::setw(15) << std::left << tmp_move->getName();
        out << Termcode::RESET;
        out << std::setw(2) << std::right << tmp_move->getPP();
        out << std::setw(6) << ""; // space between moves
    }
    return out;
}
