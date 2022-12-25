#ifndef __TRAINER_H__
#define __TRAINER_H__

#include <string>
#include <vector>
#include <memory>

class Pokemon;

class Trainer {
    std::string name;
    std::vector<std::unique_ptr<Pokemon>> team;
public:
    Trainer(const std::string& s);
    virtual ~Trainer() = 0;

    const std::string& getName() const;
    void battle(Trainer& foe);
    void add(std::unique_ptr<Pokemon>& p); 
};

#endif
