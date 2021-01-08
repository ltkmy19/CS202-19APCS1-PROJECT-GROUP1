#ifndef _CreatorVehicle_h_
#define _CreatorVehicle_h_

#include "CVehicle.h"

class CreatorVehicle {
protected:
    int x, y;
public:
    CreatorVehicle() {};
    CreatorVehicle(int tmpX, int tmpY) {
        x = tmpX;
        y = tmpY;
    }
    virtual ~CreatorVehicle() {};
    virtual CVEHICLE* factoryMethod() = 0;
};

class CreatorTruck : public CreatorVehicle {
public:
    CreatorTruck(int tmpX, int tmpY) : CreatorVehicle(tmpX, tmpY) {};
    ~CreatorTruck() {};
    CVEHICLE* factoryMethod()
    {
        CVEHICLE* tmp = new CTRUCK(x, y);
        return tmp;
    }
};

class CreatorCar : public CreatorVehicle {
public:
    CreatorCar(int tmpX, int tmpY) : CreatorVehicle(tmpX, tmpY) {};
    ~CreatorCar() {};
    CVEHICLE* factoryMethod()
    {
        CVEHICLE* tmp = new CCAR(x, y);
        return tmp;
    }
};

#endif
