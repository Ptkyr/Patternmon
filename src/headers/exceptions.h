#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <string>

class FourMoves {
    std::string poke;
public:
    std::string what() {
        return poke + " cannot learn more than four moves.";
    }
};

#endif
