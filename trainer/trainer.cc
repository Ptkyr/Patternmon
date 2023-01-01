#include "trainer.h"
#include "exceptions.h"
#include "pokemon.h"
#include <utility>
#include <stdexcept>
#include <iostream>

Trainer::Trainer(const std::string& s): name{s} {}

Trainer::~Trainer() = default;

const std::string& Trainer::getName() const {
    return name;
}

void Trainer::add(std::unique_ptr<Pokemon>& p) {
    if (team.size() == 6) {
        throw MaxTeamSize{};
    }
    team.emplace_back(std::move(p));
}

void Trainer::battle(Trainer& foe) {
    std::cout << "Battle between " << name << " and ";
    std::cout << foe.name << " has begun!" << std::endl;
    size_t cur_index = 0;
    size_t opp_index = 0;
    Pokemon* cur = team[0].get();
    Pokemon* opp = foe.team[0].get();
    while (true) {
        try {
            cur->attack(*opp);
        } catch (MoveExcept& me) {
            std::cerr << me.what() << std::endl;
        }
        if (opp->fainted()) {
            ++opp_index;
            try {
                opp = foe.team.at(opp_index).get();
            } catch (std::out_of_range& oor) {
                std::cerr << name << " defeated " << foe.name << "!" << std::endl;
                return;
            }
        }
        try {
            std::cout << foe.name << "'s ";
            opp->attack(*cur);
        } catch (MoveExcept& me) {
            std::cerr << me.what() << std::endl;
        }
        if (cur->fainted()) {
            ++cur_index;
            try {
                cur = team.at(cur_index).get();
            } catch (std::out_of_range& oor) {
                std::cerr << name << " blacked out!" << std::endl;
                return;
            }
        }
    }
}

std::istream& operator>>(std::istream& in, Trainer& t) {
    t.team.clear();
    while (in) {
        auto tmp = Pokemon::spawn(in);
        t.add(tmp);
    }
    return in;
}
