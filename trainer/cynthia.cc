#include "cynthia.h"
#include "species.h"
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
#include "types.h"

Cynthia::Cynthia(): Trainer("Cynthia") {
    std::unique_ptr<Pokemon> spiritomb = std::make_unique<Species>("Spiritomb", Stats{50, 92, 108, 92, 108, 35});
    addType<Ghost, Dark>(spiritomb);
    spiritomb->learn(std::make_unique<GhostMove>("Shadow Ball", Category::Special, 80, 15));
    add(spiritomb);

    std::unique_ptr<Pokemon> garchomp = std::make_unique<Species>("Garchomp", Stats{108, 130, 95, 80, 85, 102});
    addType<Dragon, Ground>(garchomp);
    garchomp->learn(std::make_unique<GroundMove>("Earthquake", Category::Physical, 100, 15));
    add(garchomp);

    std::unique_ptr<Pokemon> eelektross = std::make_unique<Species>("Eelektross", Stats{85, 115, 80, 105, 80, 50});
    addType<Electric>(eelektross);
    eelektross->learn(std::make_unique<FireMove>("Flamethrower", Category::Special, 90, 15));
    add(eelektross);

    std::unique_ptr<Pokemon> milotic = std::make_unique<Species>("Milotic", Stats{95, 60, 79, 100, 125, 81});
    addType<Water>(milotic);
    milotic->learn(std::make_unique<WaterMove>("Hydro Pump", Category::Special, 110, 15));
    add(milotic);

    std::unique_ptr<Pokemon> braviary = std::make_unique<Species>("Braviary", Stats{100, 123, 75, 57, 75, 80});
    addType<Normal, Flying>(braviary);
    braviary->learn(std::make_unique<FlyingMove>("Brave Bird", Category::Physical, 120, 15));
    add(braviary);

    std::unique_ptr<Pokemon> lucario = std::make_unique<Species>("Lucario", Stats{70, 110, 70, 115, 70, 90});
    addType<Fighting, Steel>(lucario);
    lucario->learn(std::make_unique<FightingMove>("Aura Sphere", Category::Special, 80, 20));
    add(lucario);
}
