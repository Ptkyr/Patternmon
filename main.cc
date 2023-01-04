#include "cynthia.h"
#include "player.h"
#include "singles.h"
#include "exceptions.h"
#include <fstream>

using std::unique_ptr;
using std::make_unique;

int main() {
    Player pete{"Pete"};
    Cynthia cynthia;

    std::ifstream team{"./teamfiles/modern_dragmag_finch.txt"};
    team >> pete;

    // pete.battle(cynthia);
    Singles ps{&pete, &cynthia};
    ps.start();
}
