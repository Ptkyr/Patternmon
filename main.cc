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

using std::unique_ptr;
using std::make_unique;
using std::make_shared;

int main() {
    unique_ptr<Pokemon> wtf = make_unique<Species>("Abomination", Stats{80, 70, 70, 90, 100, 70});
    addType<Normal>(wtf);
    addType<Fire>(wtf);
    addType<Water>(wtf);
    addType<Grass>(wtf);
    addType<Electric>(wtf);
    addType<Ice>(wtf);
    addType<Fighting>(wtf);
    addType<Poison>(wtf);
    addType<Ground>(wtf);
    addType<Flying>(wtf);
    addType<Psychic>(wtf);
    addType<Bug>(wtf);
    addType<Rock>(wtf);
    addType<Ghost>(wtf);
    addType<Dragon>(wtf);
    addType<Dark>(wtf);
    addType<Steel>(wtf);
    addType<Fairy>(wtf);
    wtf->learn(make_shared<GhostMove>("Shadow Ball", Category::Special, 90, 15));
    wtf->learn(make_shared<DragonMove>("Draco Meteor", Category::Special, 90, 15));
    wtf->learn(make_shared<WaterMove>("Water Pulse", Category::Special, 20, 10));
    wtf->learn(make_shared<FlyingMove>("Aerial Ace", Category::Physical, 75, 15));

    /*
    try {
        wtf->learn(make_shared<WaterMove>("Scald", Category::Special, 80, 15));
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
    wtf->attack(*rotom_mow);
    rotom_mow->attack(*wtf);

    unique_ptr<Route> route = make_unique<ColdStorage>();

    /*
    try {
        for (int i = 0; i < 30; ++i) {
            unique_ptr<Pokemon> encounter{route->spawn()};
            rotom_mow->attack(*encounter);
        }
        // Switch to a different Factory,
        //  different Pokemon will spawn
        route = make_unique<Route5>();
        for (int i = 0; i < 30; ++i) {
            unique_ptr<Pokemon> encounter{route->spawn()};
            rotom_mow->attack(*encounter);
        }
    } catch (MoveExcept& me) {
        // Should run out of PP at some point
        std::cerr << me.what() << std::endl;
    }
    */
}
