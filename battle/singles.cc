#include "singles.h"
#include "trainer.h"
#include "pokemon.h"
#include "move.h"
#include "exceptions.h"
#include <utility>

Singles::Singles(Trainer* x, Trainer* y): you{x}, foe{y},
    cur{x->getLead()}, opp{y->getLead()} {}

void Singles::initialMessage() {
    std::cout << "Battle started between ";
    std::cout << you->getName() << " and " << foe->getName();
    std::cout << "!" << std::endl;
}

void Singles::turn() {
    while (cur) {
        try {
            std::cout << *cur;
            Move* attack = you->getMove();
            std::cout << cur->getName() << " used " << *attack << "!" << std::endl;
            if (attack->getPP() <= 0) throw NoPPExcept{};
            attack->hit(*opp);
            attack->use();
        } catch (MoveExcept& mex) {
            std::cerr << mex.what() << std::endl;
        }
        if (opp->fainted()) {
            foe->switchOut();
            opp = foe->getLead();
        }
        std::swap(cur, opp);
        std::swap(you, foe);
    }
}

void Singles::endMessage() {
    std::cout << you->getName() << " won the battle!" << std::endl; 
}
