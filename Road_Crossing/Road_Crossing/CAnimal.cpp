#include "CAnimal.h"
#include "CGame.h"
#pragma

CANIMAL::CANIMAL(int x, int y) 
{

}

void CANIMAL::Move(int x, int y)
{

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

CDINAUSOR::CDINAUSOR(int x, int y) : CANIMAL(x, y) 
{

}

void CDINAUSOR::Draw(int tmpX, int tmpY)
{
	x += 3 * Way; //toc do 
	tmpX = x;

	if (x > Endlane + Startlane - 1 || x <= Startlane) return;

	gotoXY(tmpX, tmpY + 1);
	cout << char(223);

	cout << char(178);
	gotoXY(tmpX - 1, tmpY + 1);
	cout << char(178);
	gotoXY(tmpX, tmpY);
	cout << char(203);
	gotoXY(tmpX, tmpY);
}

CBIRD::CBIRD(int x, int y) : CANIMAL(x, y) 
{

}

void CBIRD::Draw(int x, int y) 
{


}

