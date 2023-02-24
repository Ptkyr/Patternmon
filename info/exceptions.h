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

class AttackMiss: public MoveExcept {
public:
    std::string what() const override {
        return "But it failed!";
    }
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

class MaxTeamSize {
public:
    std::string what() const {
        return "Party size cannot exceed six.";
    }
};

class ReadError {
public:
    std::string file;
    std::string what() const {
        return "Fatal error reading from " + file;
    }
};

class TooBoosted {
    std::string what() const {
        return "Cannot go any higher!";
    }
};

class Fainted {};

class BattleError {
public:
    virtual std::string what() const = 0;
};

class BattleInterrupt: public BattleError {
public:
    std::string what() const override {
        return "Battle interrupted.";
    }
};

#endif
