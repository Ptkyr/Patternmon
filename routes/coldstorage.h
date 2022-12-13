#ifndef __COLDSTORAGE_H__
#define __COLDSTORAGE_H__

#include "route.h"

class ColdStorage: public Route {
public:
    ColdStorage(): Route({"Herdier",
                          "Timburr",
                          "Minccino",
                          "Vanillite"},
                         {35, 55, 70, 100}) {}
};

#endif
