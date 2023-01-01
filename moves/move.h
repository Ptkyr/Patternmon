#ifndef __MOVE_H__
#define __MOVE_H__

#include <string>
#include <memory>

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
    const int acc;
    int pp;
public:
    Move(std::string n, Category c, int base, int acc, int pp);
    virtual ~Move() = 0;

    int getBP() const;
    int getAcc() const;
    int getPP() const;
    Category getPS() const;
    virtual std::string getName() const;
    void use();

    virtual void hit(Pokemon& p) = 0;
};

std::unique_ptr<Move> makeMove(const std::string name);

#endif
