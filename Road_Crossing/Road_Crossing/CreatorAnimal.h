#ifndef _CreatorAnimal_h_
#define _CreatorAnimal_h_

#include "CAnimal.h"

class CreatorAnimal {
protected:
    int x, y;
public:
    CreatorAnimal(){};
    CreatorAnimal(int tmpX, int tmpY){
        x = tmpX;
        y = tmpY;
    }
    virtual ~CreatorAnimal() {};
    virtual CANIMAL* factoryMethod() = 0;
};

class CreatorDinausor : public CreatorAnimal {
public:
    CreatorDinausor(int tmpX, int tmpY) : CreatorAnimal(tmpX,tmpY) {};
    ~CreatorDinausor() {};
    CANIMAL* factoryMethod()
    {
        CANIMAL* tmp = new CDINAUSOR(x,y);
        return tmp;
    }
};

class CreatorBird : public CreatorAnimal {
public:
    CreatorBird(int tmpX, int tmpY) : CreatorAnimal(tmpX,tmpY) {};
    ~CreatorBird() {};
    CANIMAL* factoryMethod()
    {
        CANIMAL* tmp = new CBIRD(x,y);
        return tmp;
    }
};

#endif
