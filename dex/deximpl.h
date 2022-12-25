#ifndef __DEXIMPL_H__
#define __DEXIMPL_H__

#include <memory>
#include <string>
#include <vector>

class Pokemon;

class DexImpl {
  protected:
    std::vector<std::string> statNames{"HP", "ATK", "DEF", "SPATK", "SPDEF", "SPE"};
  public:
    std::unique_ptr<Pokemon> spawn(const std::string& name) const;
    virtual void print(const std::string& name) const = 0;
    virtual ~DexImpl();
};

#endif
