#include "CVehicle.h"

//CVEHICLE

CVEHICLE::CVEHICLE(int tmpX, int tmpY)
{
	x = tmpX;
	y = tmpY;
}

void CVEHICLE::Move(int tmpX, int tmpY)
{
	x = tmpX;
	y = tmpY;
}

bool CVEHICLE::IsDone()
{
	return true;
}

//CTRUCK
CTRUCK::CTRUCK(int tmpX, int tmpY) : CVEHICLE::CVEHICLE(tmpX,tmpY)
{

}

void CTRUCK::Draw(int tmpX, int tmpY)
{

}

//CCAR
CCAR::CCAR(int tmpX, int tmpY) : CVEHICLE::CVEHICLE(tmpX, tmpY)
{

}

void CCAR::Draw(int tmpX, int tmpY)
{

}