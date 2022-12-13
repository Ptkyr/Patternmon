#ifndef __ROUTE_H__
#define __ROUTE_H__

#include <vector>
#include <string>

class Pokemon;

class Route {
    std::vector<std::string> spawns;
    std::vector<double> chances;
public:
    Route(std::vector<std::string> s, std::vector<double> c);
    virtual ~Route() = 0;

    Pokemon* spawn();
};

#endif
