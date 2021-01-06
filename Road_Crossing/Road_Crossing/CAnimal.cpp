#include "CAnimal.h"

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
		GotoXY(x - 2, y - 1); cout << "    ";
		GotoXY(x - 2, y); cout << "    ";
		GotoXY(x - 1, y + 1); cout << "___";
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

	GotoXY(tmpX, tmpY + 1);
	cout << char(223);

	cout << char(178);
	GotoXY(tmpX - 1, tmpY + 1);
	cout << char(178);
	GotoXY(tmpX, tmpY);
	cout << char(203);
	GotoXY(tmpX, tmpY);
}

CBIRD::CBIRD(int x, int y) : CANIMAL(x, y) 
{

}

void CBIRD::Draw(int x, int y) 
{


}

