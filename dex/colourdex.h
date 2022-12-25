#ifndef __COLOURDEX_H__
#define __COLOURDEX_H__

#include "deximpl.h"
#include <iostream>

class ColourDex: public DexImpl {
    std::ostream& out = std::cout;
    void colourNumber(const int& n) const;
  public:
    void print(const std::string& name) const override;
    ~ColourDex();
};

#endif
