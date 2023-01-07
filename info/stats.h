#ifndef __STATS_H__
#define __STATS_H__

#include <utility>

class Stats {
    class Boost {
        int stage = 0;
    public:
        Boost& operator++();
        Boost& operator--();
        double operator()() const;
        void operator*();
    };
public:
    const int hp;
    std::pair<const int, Boost> atk;
    std::pair<const int, Boost> def;
    std::pair<const int, Boost> spatk;
    std::pair<const int, Boost> spdef;
    std::pair<const int, Boost> spe;

    Stats(int h, int a, int d, int spa, int spd, int speed);
    int HP() const;
    int ATK() const;
    int DEF() const;
    int SPATK() const;
    int SPDEF() const;
    int SPE() const;
    int operator[](const int& x) const;
};

#endif
