#include "CAnimal.h"
#include "CGame.h"
#pragma

CANIMAL::CANIMAL(int tmpX, int tmpY)
{
	x = tmpX;
	y = tmpY;
	if (tmpX >= Endlane) Way = -1;
	else Way = 1;
}

void CANIMAL::Move(int tmpX, int tmpY)
{
	if (x <= Endlane + Startlane - 1 && x >= Startlane + 1)
	{
		gotoXY(x - 2, y - 1); 
		cout << "    ";

		gotoXY(x - 2, y);
		cout << "    ";

		gotoXY(x - 1, y + 1); 
		cout << "___";
	}
}

bool CANIMAL::IsDone()
{
	if ((Way == 1 && x >= Endlane) || (Way == -1 && x <= Startlane + 3))
	{
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

CDINAUSOR::CDINAUSOR(int tmpX, int tmpY) : CANIMAL(tmpX, tmpY) 
{
	Draw(tmpX, tmpY);
}

void CDINAUSOR::Draw(int tmpX, int tmpY)
{
	x += 3 * Way; //toc do 
	x = tmpX;

	if (x > Endlane + Startlane - 1 || x <= Startlane) return;

	gotoXY(tmpX, tmpY + 1);
	cout << char(223);
	cout << char(178);
	gotoXY(tmpX - 1, tmpY + 1);
	cout << char(178);
	gotoXY(tmpX, tmpY);
	cout << char(203);
}

CBIRD::CBIRD(int tmpX, int tmpY) : CANIMAL(tmpX, tmpY) 
{
	Draw(tmpX, tmpY);
}

void CBIRD::Draw(int tmpX, int tmpY) 
{
	x += 4 * Way; 
	tmpX = x;

	if (tmpX > Endlane + Startlane - 1 || tmpX <= Startlane) 
		return;

	gotoXY(tmpX, tmpY);
	cout << char(254);
	cout << char(223);
	gotoXY(tmpX - 1, tmpY);
	cout << char(223);
}

