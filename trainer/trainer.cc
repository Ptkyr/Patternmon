#include "trainer.h"
#include "exceptions.h"
#include "pokemon.h"
#include <utility>
#include <stdexcept>
#include <iostream>
#include <random>

Trainer::Trainer(const std::string& s): name{s} {}

Trainer::~Trainer() = default;

const std::string& Trainer::getName() const {
    return name;
}

Pokemon* Trainer::getLead() const {
    return lead;
}

void Trainer::add(std::unique_ptr<Pokemon>& p) {
    if (team.size() == 6) {
        throw MaxTeamSize{};
    }
    team.emplace_back(std::move(p));
}

void Trainer::switchOut() {
    // Find the first alive pokemon
    //  and switch to it, return 
    //  nullptr if whole party is dead
    for (const auto& p: team) {
        if (!p->fainted()) {
            lead = p.get();
            return;
        }
    }
    lead = nullptr;
}

Move* Trainer::getMove() const {
    std::random_device rd;
    std::mt19937 gen{rd()};
    std::uniform_int_distribution<> dist{0, static_cast<int>(lead->moveCount() - 1)};
    return lead->getMove(static_cast<size_t>(dist(gen)));
}

std::istream& operator>>(std::istream& in, Trainer& t) {
    t.team.clear();
    while (in) {
        auto tmp = Pokemon::spawn(in);
        t.add(tmp);
    }
    t.lead = t.team.at(0).get();
    return in;
}
