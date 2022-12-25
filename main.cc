#include "normal.h"
#include "fire.h"
#include "water.h"
#include "grass.h"
#include "electric.h"
#include "ice.h"
#include "fighting.h"
#include "poison.h"
#include "ground.h"
#include "flying.h"
#include "psychic.h"
#include "bug.h"
#include "rock.h"
#include "ghost.h"
#include "dragon.h"
#include "dark.h"
#include "steel.h"
#include "fairy.h"
#include "species.h"
#include "types.h"
#include "move.h"
#include "route5.h"
#include "coldstorage.h"
#include "pokedex.h"
#include "exceptions.h"
#include "cynthia.h"
#include "player.h"

using std::unique_ptr;
using std::make_unique;
using std::make_shared;

int main() {
    Pokedex dex;
    dex.prettyDex();
    Player pete{"Pete"};
    Cynthia cynthia;

    auto ludicolo = dex.spawn("Ludicolo");
    addType<Normal, Flying, Ground>(ludicolo);
    ludicolo->learn(make_unique<GhostMove>("Shadow Ball", Category::Special, 80, 15));
    ludicolo->learn(make_unique<DragonMove>("Draco Meteor", Category::Special, 140, 15));
    ludicolo->learn(make_unique<WaterMove>("Surf", Category::Special, 90, 10));
    ludicolo->learn(make_unique<FlyingMove>("Acrobatics", Category::Physical, 110, 15));

    auto magnezone = dex.spawn("Magnezone");
    addType<Normal, Grass, Ghost>(magnezone);
    magnezone->learn(make_unique<GrassMove>("Leaf Storm", Category::Special, 140, 15));
    magnezone->learn(make_unique<ElectricMove>("Thunderbolt", Category::Special, 90, 15));
    magnezone->learn(make_unique<IceMove>("Ice Beam", Category::Special, 90, 15));
    magnezone->learn(make_unique<SteelMove>("Iron Head", Category::Special, 90, 15));

    pete.add(ludicolo);
    pete.add(magnezone);

    pete.battle(cynthia);

    /*
    // Use a random attack
    ludicolo->attack(*magnezone);
    magnezone->attack(*ludicolo);

    unique_ptr<Route> route = make_unique<ColdStorage>();

    try {
        for (int i = 0; i < 6; ++i) {
            auto encounter = route->spawn();
            ludicolo->attack(*encounter);
        }
        // Switch to a different Factory,
        //  different Pokemon will spawn
        route = make_unique<Route5>();
        for (int i = 0; i < 6; ++i) {
            auto encounter = route->spawn();
            magnezone->attack(*encounter);
        }
    } catch (MoveExcept& me) {
        // Should run out of PP at some point
        std::cerr << me.what() << std::endl;
    }
    */
}
