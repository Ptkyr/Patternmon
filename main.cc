#include "normal.h"
#include "fire.h"
#include "water.h"
#include "grass.h"
#include "electric.h"
#include "ice.h"
#include "fighting.h"
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
    addType<Grass>(ludicolo);
    addType<Water>(ludicolo);
    addType<Ice>(ludicolo);
    addType<Fighting>(ludicolo);
    ludicolo->learn(make_shared<GhostMove>("Shadow Ball", Category::Special, 90, 15));
    ludicolo->learn(make_shared<DragonMove>("Draco Meteor", Category::Special, 90, 15));
    ludicolo->learn(make_shared<WaterMove>("Water Pulse", Category::Special, 20, 10));
    ludicolo->learn(make_shared<FlyingMove>("Aerial Ace", Category::Physical, 75, 15));

    /*
    try {
        ludicolo->learn(make_shared<WaterMove>("Scald", Category::Special, 80, 15));
    } catch (MoveExcept& me) {
        std::cerr << me.what() << std::endl;
    }
    */

    unique_ptr<Pokemon> rotom_mow = make_unique<Species>("Rotom-Mow", Stats{50, 65, 107, 105, 107, 86});
    addType<Grass>(rotom_mow);
    addType<Electric>(rotom_mow);
    addType<Normal>(rotom_mow);
    rotom_mow->learn(make_shared<PsychicMove>("Psychic", Category::Special, 140, 15));
    rotom_mow->learn(make_shared<FairyMove>("Dazzling Gleam", Category::Special, 90, 15));
    rotom_mow->learn(make_shared<IceMove>("Ice Beam", Category::Special, 90, 15));
    rotom_mow->learn(make_shared<SteelMove>("Iron Head", Category::Special, 90, 15));

    // Use a random attack
    ludicolo->attack(*rotom_mow);
    rotom_mow->attack(*ludicolo);

    unique_ptr<Route> route = make_unique<ColdStorage>();

    try {
        for (int i = 0; i < 7; ++i) {
            unique_ptr<Pokemon> encounter{route->spawn()};
            rotom_mow->attack(*encounter);
        }
        // Switch to a different Factory,
        //  different Pokemon will spawn
        route = make_unique<Route5>();
        for (int i = 0; i < 7; ++i) {
            unique_ptr<Pokemon> encounter{route->spawn()};
            rotom_mow->attack(*encounter);
        }
    } catch (MoveExcept& me) {
        // Should run out of PP at some point
        std::cerr << me.what() << std::endl;
    }
}
