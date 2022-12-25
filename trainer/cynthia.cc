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
#include "pokedex.h"

Cynthia::Cynthia(): Trainer("Cynthia") {
    Pokedex dex;
    auto spiritomb = dex.spawn("Spiritomb");
    spiritomb->learn(std::make_unique<GhostMove>("Shadow Ball", Category::Special, 80, 15));
    add(spiritomb);

    auto garchomp = dex.spawn("Garchomp");
    garchomp->learn(std::make_unique<GroundMove>("Earthquake", Category::Physical, 100, 15));
    add(garchomp);

    auto eelektross = dex.spawn("Eelektross");
    eelektross->learn(std::make_unique<FireMove>("Flamethrower", Category::Special, 90, 15));
    add(eelektross);

    auto milotic = dex.spawn("Milotic");
    milotic->learn(std::make_unique<WaterMove>("Hydro Pump", Category::Special, 110, 15));
    add(milotic);

    auto braviary = dex.spawn("Braviary");
    braviary->learn(std::make_unique<FlyingMove>("Brave Bird", Category::Physical, 120, 15));
    add(braviary);

    auto lucario = dex.spawn("Lucario");
    lucario->learn(std::make_unique<FightingMove>("Aura Sphere", Category::Special, 80, 20));
    add(lucario);
}
