#include "singles.h"
#include "trainer.h"
#include "pokemon.h"
#include "exceptions.h"

Singles::Singles(Trainer* x, Trainer* y): you{x}, foe{y},
    cur{x->getLead()}, opp{y->getLead()} {}

void Singles::initialMessage() {
    std::cout << "Battle started between ";
    std::cout << you->getName() << " and " << foe->getName();
    std::cout << "!" << std::endl;
}

void Singles::turn() {
    while (true) {
        try {
            cur->attack(*opp);
        } catch (MoveExcept& mex) {
            std::cerr << mex.what() << std::endl;
        }
        if (opp->fainted()) opp = foe->getNext();
        if (!opp) return;
        std::swap(cur, opp);
        std::swap(you, foe);
    }
}

void Singles::endMessage() {
    std::cout << you->getName() << " won the battle!" << std::endl; 
}
