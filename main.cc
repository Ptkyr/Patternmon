#include "water.h"
#include "grass.h"
#include "fire.h"
#include "electric.h"
#include "species.h"
#include "types.h"
#include "move.h"
#include "route5.h"
#include "coldstorage.h"
#include "pokedex.h"
#include "exceptions.h"

using std::unique_ptr;
using std::make_unique;
using std::make_shared;

int main() {
    unique_ptr<Pokemon> ludicolo = make_unique<Species>("Ludicolo", Stats{80, 70, 70, 90, 100, 70});
    ludicolo = make_unique<Grass>(ludicolo.release());
    ludicolo = make_unique<Water>(ludicolo.release());
    ludicolo->learn(make_shared<WaterMove>("Surf", Category::Special, 90, 15));
    ludicolo->learn(make_shared<GrassMove>("Energy Ball", Category::Special, 90, 15));
    ludicolo->learn(make_shared<GroundMove>("Mud Slap", Category::Special, 20, 10));
    ludicolo->learn(make_shared<ElectricMove>("Thunder Punch", Category::Physical, 75, 15));

    try {
        ludicolo->learn(make_shared<WaterMove>("Scald", Category::Special, 80, 15));
    } catch (MoveExcept& me) {
        std::cerr << me.what() << std::endl;
    }

    unique_ptr<Pokemon> rotom_mow = make_unique<Species>("Rotom-Mow", Stats{50, 65, 107, 105, 107, 86});
    rotom_mow = make_unique<Grass>(rotom_mow.release());
    rotom_mow = make_unique<Electric>(rotom_mow.release());
    rotom_mow->learn(make_shared<GrassMove>("Leaf Storm", Category::Special, 140, 15));
    rotom_mow->learn(make_shared<ElectricMove>("Volt Switch", Category::Special, 70, 32));

    // Use a random attack
    ludicolo->attack(*rotom_mow);
    rotom_mow->attack(*ludicolo);

    ColdStorage cs;
    unique_ptr<Pokemon> encounter{cs.spawn()};
    rotom_mow->attack(*encounter);

    unique_ptr<Pokemon> lanturn = make_unique<Species>("Lanturn", Stats{125, 58, 58, 76, 76, 67});
    lanturn = make_unique<Water>(lanturn.release());
    lanturn = make_unique<Electric>(lanturn.release());

    try {
        lanturn->attack(*rotom_mow);
    } catch (MoveExcept& me) {
        std::cerr << me.what() << std::endl;
    }
}
