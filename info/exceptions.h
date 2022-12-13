#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <string>

class MoveExcept {
protected:
    std::string poke;
    MoveExcept(): poke{} {}
    MoveExcept(std::string s): poke{s} {}
public:
    virtual std::string what() const = 0;
};

class FourMovesExcept: public MoveExcept {
public:
    FourMovesExcept(std::string s): MoveExcept{s} {}
    std::string what() const override {
        return poke + " cannot learn more than four moves.";
    }
};

class NoMovesExcept: public MoveExcept {
public:
    NoMovesExcept(std::string s): MoveExcept{s} {}
    std::string what() const override {
        return poke + " has no moves!";
    }
};

class NoPPExcept: public MoveExcept {
public:
    NoPPExcept(): MoveExcept{} {}
    std::string what() const override {
        return "There's no PP left for that move!";
    }
};

class SpawnError {
public:
    std::string what() const {
        return "Could not generate random encounter.";
    }
};

#endif
