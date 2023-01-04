#ifndef __BATTLE_H__
#define __BATTLE_H__

class Battle {
    virtual void initialMessage() = 0;
    virtual void turn() = 0;
    virtual void endMessage() = 0;
public:
    void start();
    virtual ~Battle() = 0;
};

#endif
