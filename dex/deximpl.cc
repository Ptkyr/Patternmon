#include "deximpl.h"

const Stats& DexImpl::getStats(std::string name) const {
    return dex.at(name);
}
