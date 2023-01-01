#include "cynthia.h"
#include "pokemon.h"
#include "types.h"
#include "pokedex.h"

Cynthia::Cynthia(): Trainer("Cynthia") {
    Pokedex dex;
    auto spiritomb = dex.spawn("Spiritomb");
    spiritomb->learn(makeMove("Shadow Ball"));
    add(spiritomb);

    auto garchomp = dex.spawn("Garchomp");
    garchomp->learn(makeMove("Earthquake"));
    add(garchomp);

    auto eelektross = dex.spawn("Eelektross");
    eelektross->learn(makeMove("Flamethrower"));
    add(eelektross);

    auto milotic = dex.spawn("Milotic");
    milotic->learn(makeMove("Hydro Pump"));
    add(milotic);

    auto braviary = dex.spawn("Braviary");
    braviary->learn(makeMove("Brave Bird"));
    add(braviary);

    auto lucario = dex.spawn("Lucario");
    lucario->learn(makeMove("Aura Sphere"));
    add(lucario);
}
