#include "CPeople.h"

CPEOPLE::CPEOPLE(int x, int y, char** _map, char type) {
	mX = x;
	mY = y;
	map[0][0] = _map[0][0];
	map[0][1] = _map[0][1];
	map[0][2] = _map[0][2];
	map[1][0] = _map[1][0];
	map[1][1] = _map[1][1];
	map[1][2] = _map[1][2];
	map[2][0] = _map[2][0];
	map[2][1] = _map[2][1];
	map[2][2] = _map[2][2];
	this->type = type;
}
void CPEOPLE::ReDraw(int x, int y, char type) {
	if (type == 1) {
		gotoXY(x, y);
		Brown();
		cout << map[1][1];
		White();
		gotoXY(x - 1, y + 1);
		cout << map[0][2];
		gotoXY(x + 1, y - 1);
		cout << map[2][0];
		gotoXY(x - 1, y - 1);
		cout << map[0][0];
		gotoXY(x + 1, y + 1);
		cout << map[2][2];
		gotoXY(x, y - 1);
		cout << map[1][0];
	}
	else {
		gotoXY(x, y);
		LightMagenta();
		cout << map[1][1];
		White();
		gotoXY(x - 1, y + 1);
		cout << map[0][2];
		gotoXY(x - 1, y);
		cout << map[0][1];
		gotoXY(x + 1, y);
		cout << map[2][1];
		gotoXY(x + 1, y - 1);
		cout << map[2][0];
		gotoXY(x - 1, y - 1);
		cout << map[0][0];
		gotoXY(x + 1, y + 1);
		cout << map[2][2];
		gotoXY(x, y - 1);
		cout << map[1][0];
	}

}

void CPEOPLE:: Up(int x) {
	gotoXY(mX, mY);// ve nguoi
	cout << ' ';
	gotoXY(mX - 1, mY + 1);
	cout << '_';
	gotoXY(mX + 1, mY - 1);
	cout << ' ';
	gotoXY(mX - 1, mY - 1);
	cout << ' ';
	gotoXY(mX + 1, mY + 1);
	cout << '_';
	gotoXY(mX, mY - 1);
	cout << ' ';
	gotoXY(mX, mY + 1);
	cout << '_';
	gotoXY(mX + 1, mY );
	cout << ' ';
	gotoXY(mX - 1, mY);
	cout << ' ';
	mY -= x;
	ReDraw(mX, mY, type);
}

void CPEOPLE::Down(int x) {
	gotoXY(mX, mY);// ve nguoi
	cout << ' ';
	gotoXY(mX - 1, mY + 1);
	cout << '_';
	gotoXY(mX + 1, mY - 1);
	cout << ' ';
	gotoXY(mX - 1, mY - 1);
	cout << ' ';
	gotoXY(mX + 1, mY + 1);
	cout << '_';
	gotoXY(mX, mY - 1);
	cout << ' ';
	gotoXY(mX, mY + 1);
	cout << '_';
	gotoXY(mX + 1, mY);
	cout << ' ';
	gotoXY(mX - 1, mY);
	cout << ' ';
	mY += x;
	ReDraw(mX, mY, type);
}
void CPEOPLE:: Left(int x) {
	gotoXY(mX, mY);// ve nguoi
	cout << ' ';
	gotoXY(mX - 1, mY + 1);
	cout << '_';
	gotoXY(mX + 1, mY - 1);
	cout << ' ';
	gotoXY(mX - 1, mY - 1);
	cout << ' ';
	gotoXY(mX + 1, mY + 1);
	cout << '_';
	gotoXY(mX, mY - 1);
	cout << ' ';
	gotoXY(mX, mY + 1);
	cout << '_';
	gotoXY(mX + 1, mY);
	cout << ' ';
	gotoXY(mX - 1, mY);
	cout << ' ';
	mX -= 4;
	ReDraw(mX, mY, type);
}
void CPEOPLE:: Right(int x) {
	gotoXY(mX, mY);// ve nguoi
	cout << ' ';
	gotoXY(mX - 1, mY + 1);
	cout << '_';
	gotoXY(mX + 1, mY - 1);
	cout << ' ';
	gotoXY(mX - 1, mY - 1);
	cout << ' ';
	gotoXY(mX + 1, mY + 1);
	cout << '_';
	gotoXY(mX, mY - 1);
	cout << ' ';
	gotoXY(mX, mY + 1);
	cout << '_';
	gotoXY(mX + 1, mY);
	cout << ' ';
	gotoXY(mX - 1, mY);
	cout << ' ';
	mX += x;
	ReDraw(mX, mY, type);
}
