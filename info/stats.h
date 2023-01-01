#ifndef __STATS_H__
#define __STATS_H__

class Stats {
public:
    const int hp;
    const int atk;
    const int def;
    const int spatk;
    const int spdef;
    const int spe;

    Stats(int h, int a, int d, int spa, int spd, int speed);
    int operator[](const int& x) const;
};

#endif
