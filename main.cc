#include "water.h"
#include "grass.h"
#include "fire.h"
#include "electric.h"
#include "species.h"
#include "types.h"
#include "move.h"

int main() {
    Pokemon* serperior = new Species{"Serperior", {75, 75, 95, 75, 95, 113}};
    serperior = new Grass{serperior};
    serperior->learn(new GrassMove{"Leaf Storm", Category::Special, 140, 15});
    serperior->learn(new FireMove{"Hidden Power Fire", Category::Special, 60, 15});

    Pokemon* ludicolo = new Species{"Ludicolo", {80, 70, 70, 90, 100, 70}};
    ludicolo = new Grass{ludicolo};
    ludicolo = new Water{ludicolo};
    ludicolo->learn(new WaterMove{"Surf", Category::Special, 90, 15});
    ludicolo->learn(new GrassMove{"Energy Ball", Category::Special, 90, 15});

    Pokemon* rotom_mow = new Species{"Rotom-Mow", {50, 65, 107, 105, 107, 86}};
    rotom_mow = new Grass{rotom_mow};
    rotom_mow = new Electric{rotom_mow};
    rotom_mow->learn(new GrassMove{"Leaf Storm", Category::Special, 140, 15});
    rotom_mow->learn(new ElectricMove{"Volt Switch", Category::Special, 70, 32});

    // Use all attacks
    serperior->attack(*ludicolo);
    ludicolo->attack(*serperior);
    serperior->attack(*rotom_mow);
    rotom_mow->attack(*ludicolo);

    delete serperior;
    delete ludicolo;
    delete rotom_mow;
}
