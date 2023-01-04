#include "battle.h"

Battle::~Battle() = default;

void Battle::start() {
    initialMessage();
    turn();
    endMessage();
}
