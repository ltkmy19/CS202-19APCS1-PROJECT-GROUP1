#include "CVehicle.h"
#include "CGame.h"

//CVEHICLE

CVEHICLE::CVEHICLE(int tmpX, int tmpY)
{
	x = tmpX;
	y = tmpY;

	if (x >= Endlane)
		Way = -1;
	else Way = 1;
}

void CVEHICLE::Move(int tmpX, int tmpY)
{
	if (x <= Endlane + Startlane - 1 && x >= Startlane + 1) {
		gotoXY(x - 2, y - 1); 
		cout << "    ";
		gotoXY(x - 2, y); 
		cout << "    ";
		gotoXY(x - 1, y + 1); 
		cout << "___";
	}
	Draw(x, y);
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