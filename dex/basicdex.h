#ifndef __BASICDEX_H__
#define __BASICDEX_H__

#include "deximpl.h"
#include <iostream>

class BasicDex: public DexImpl {
    std::ostream& out = std::cout;
  public:
    void print(const std::string& name) const override;
    ~BasicDex();
};

#endif
