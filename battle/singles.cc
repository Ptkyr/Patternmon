#include "singles.h"
#include "trainer.h"
#include "pokemon.h"
#include "move.h"
#include "exceptions.h"
#include "stats.h"
#include <utility>

Singles::Singles(Trainer* x, Trainer* y): you{x}, foe{y},
    cur{x->getLead()}, opp{y->getLead()} {}

void Singles::swap() {
    std::swap(cur, opp);
    std::swap(you, foe);
    std::swap(attack, defend);
}

void Singles::initialMessage() {
    std::cout << "Battle started between " << you->getName()
              << " and " << foe->getName() << "!" << std::endl;
    std::cout << you->getName() << " sent out " << cur->getName() << "!" << std::endl;
    std::cout << foe->getName() << " sent out " << opp->getName() << "!" << std::endl;
}

void Singles::turn() {
    while (cur && opp) {
        // Assume you're faster
        try { // This sucks, need a better way
            attack = you->getMove();
            defend = foe->getMove();
        } catch (NoPPExcept& npe) {
            std::cerr << npe.what() << std::endl;
            continue;
        }
        // If you aren't, just swap places
        if (cur->getStats().SPE() < opp->getStats().SPE()) swap();
        try {
            halfTurn();
            halfTurn();
        } catch (Fainted& f) {
            if (opp) {
                std::cout << foe->getName() << " sent out "
                          << opp->getName() << "!" << std::endl;
            }
        }
    }
}

void Singles::halfTurn() {
    try {
        std::cout << cur->getName() << " used " << *attack << "!" << std::endl;
        attack->hit(*opp);
        attack->use();
    } catch (MoveExcept& mex) {
        std::cerr << mex.what() << std::endl;
    }
    if (opp->fainted()) {
        foe->switchOut();
        opp = foe->getLead();
        throw Fainted{};
    }
    swap();
}

void Singles::endMessage() {
    std::cout << you->getName() << " won the battle!" << std::endl; 
}
