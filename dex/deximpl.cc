#include "deximpl.h"
#include "exceptions.h"
#include "stats.h"
#include "normal.h"
#include "fire.h"
#include "water.h"
#include "grass.h"
#include "electric.h"
#include "ice.h"
#include "fighting.h"
#include "poison.h"
#include "ground.h"
#include "flying.h"
#include "psychic.h"
#include "bug.h"
#include "rock.h"
#include "ghost.h"
#include "dragon.h"
#include "dark.h"
#include "steel.h"
#include "fairy.h"
#include "species.h"
#include "types.h"
#include <fstream>
#include <sstream>
#include <functional>
#include <map>
#include <memory>

static const std::map<std::string, std::function<void(std::unique_ptr<Pokemon>&)>> decverter {
    {"Normal", addType<Normal>},
    {"Fire", addType<Fire>},
    {"Water", addType<Water>},
    {"Grass", addType<Grass>},
    {"Electric", addType<Electric>},
    {"Ice", addType<Ice>},
    {"Fighting", addType<Fighting>},
    {"Poison", addType<Poison>},
    {"Ground", addType<Ground>},
    {"Flying", addType<Flying>},
    {"Psychic", addType<Psychic>},
    {"Bug", addType<Bug>},
    {"Rock", addType<Rock>},
    {"Ghost", addType<Ghost>},
    {"Dragon", addType<Dragon>},
    {"Dark", addType<Dark>},
    {"Steel", addType<Steel>},
    {"Fairy", addType<Fairy>},
    {"", [](std::unique_ptr<Pokemon>&){}}
};

DexImpl::~DexImpl() = default;

std::unique_ptr<Pokemon> DexImpl::spawn(const std::string& name) const {
    std::ifstream input{"./dex/pokemon.txt"};
    std::string tmp;
    while (std::getline(input, tmp)) {
        std::istringstream iss{tmp};
        std::string s;
        std::vector<std::string> entries;
        std::getline(iss, s, ',');
        std::getline(iss, s, ',');
        if (s != name) continue;
        while (getline(iss, s, ',')) {
            entries.emplace_back(std::move(s));
        }
        Stats tmp_stats{stoi(entries[3]), stoi(entries[4]),
                        stoi(entries[5]), stoi(entries[6]),
                        stoi(entries[7]), stoi(entries[8])
        };
        std::unique_ptr<Pokemon> ret = std::make_unique<Species>(name, tmp_stats);
        decverter.at(entries[0])(ret);
        decverter.at(entries[1])(ret);
        return ret;
    }
    throw SpawnError{};
}
