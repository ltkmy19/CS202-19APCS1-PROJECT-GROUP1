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
	if ((Way == -1 && x <= Startlane + 3) || (Way == 1 && x >= Endlane)) {
		gotoXY(x - 2, y - 1); 
		cout << "    ";
		gotoXY(x - 2, y); 
		cout << "    ";
		gotoXY(x - 1, y + 1); 
		cout << "___";
		return true;
	}
	return false;
}

//CTRUCK
CTRUCK::CTRUCK(int tmpX, int tmpY) : CVEHICLE::CVEHICLE(tmpX,tmpY)
{
	Draw(tmpX, tmpY);
}

void CTRUCK::Draw(int tmpX, int tmpY)
{
	x += Way; 
	tmpX = x;
	if (x > Endlane + Startlane - 1 || x <= Startlane) 
		return;
	gotoXY(tmpX - 1, tmpY + 1);
	cout << char(219); 
	cout << char(219);
	cout << char(219);
	gotoXY(tmpX - 1, tmpY);
	cout << char(219);
	cout << char(219);
}

//CCAR
CCAR::CCAR(int tmpX, int tmpY) : CVEHICLE::CVEHICLE(tmpX, tmpY)
{
	Draw(tmpX, tmpY);
}

void CCAR::Draw(int tmpX, int tmpY)
{
	x += 2 * Way; 
	tmpX = x;
	if (tmpX > Endlane +Startlane - 1 || x <= Startlane) 
		return;
	gotoXY(tmpX - 1, tmpY + 1);
	cout << char(219);
	cout << char(219);
	cout << char(219);
	gotoXY(tmpX - 1, tmpY);
	cout << char(220);
	cout << char(219);
	cout << char(220);

}