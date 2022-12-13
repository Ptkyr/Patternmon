#ifndef __ROUTEFIVE_H__
#define __ROUTEFIVE_H__

#include "route.h"

class Route5: public Route {
public:
    Route5(): Route({"Liepard",
                     "Trubbish",
                     "Minccino",
                     "Gothita"},
                     {20, 40, 70, 100}) {}
};

#endif
