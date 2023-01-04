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

Pokemon* Trainer::getLead() const {
    return team.at(0).get();
}

void Trainer::add(std::unique_ptr<Pokemon>& p) {
    if (team.size() == 6) {
        throw MaxTeamSize{};
    }
    team.emplace_back(std::move(p));
}

Pokemon* Trainer::getNext() const {
    for (const auto& p: team) {
        if (!p->fainted()) {
            return p.get();
        }
    }
    return nullptr;
}

std::istream& operator>>(std::istream& in, Trainer& t) {
    t.team.clear();
    while (in) {
        auto tmp = Pokemon::spawn(in);
        t.add(tmp);
    }
    return in;
}
