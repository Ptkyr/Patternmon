#ifndef __STATS_H__
#define __STATS_H__

#include <vector>

struct Stats {
    const int hp;
    const int atk;
    const int def;
    const int spatk;
    const int spdef;
    const int spe;

    Stats(int hp, int atk, int def, int spatk, int spdef, int spe);
};

#endif
