#ifndef __MOVE_H__
#define __MOVE_H__

#include <string>

class Pokemon;

enum class Category {
    Physical,
    Special
};

class Move {
protected:
    std::string name;
    const Category cat;
    const int bp;
    int pp;
public:
    Move(std::string n, Category c, int base, int pp);
    virtual ~Move() = 0;

    int getBP() const;
    Category getPS() const;
    virtual std::string getName() const;
    void use();

    virtual void hit(Pokemon& p) = 0;
};

#endif
