#ifndef _CreatorAnimal_h_
#define _CreatorAnimal_h_

#include "CGame.h"

class CreatorAnimal {
private:
    int x, y;
public:
    CreatorAnimal();
    virtual ~CreatorAnimal();
    virtual CANIMAL* factoryMethod() = 0;
};

class CreatorDinausor : public CreatorAnimal {
public:
    CreatorDinausor(int tmpX, int tmpY) {};
    ~CreatorDinausor() {};
    CANIMAL* factoryMethod() 
    {
        CANIMAL* x = new CDINAUSOR();
        return x;
    }
};

class CreatorBird : public CreatorAnimal {
public:
    CreatorBird(int tmpX, int tmpY) {};
    ~CreatorBird() {};
    CANIMAL* factoryMethod()
    {
        CANIMAL* x = new CBIRD();
        return x;
    }
};

#endif