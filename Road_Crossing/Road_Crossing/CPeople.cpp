#include "CPeople.h"

CPEOPLE::CPEOPLE(int x, int y, char type) {
	mX = x;
	mY = y;
	this->type = type;
	if (type == '1') {
		map[1][1] = char(219);
		map[0][2] = '/';
		map[2][0] = '/';
		map[0][0] = char(92);
		map[2][2] = char(92);
		map[1][0] = char(254);
		map[0][1] = ' ';
		map[2][1] = ' ';
		map[1][2] = ' ';
	}
	else {
		map[1][1] = char(219);
		map[0][2] = '/';
		map[2][0] = char(126);
		map[0][1] = '/';
		map[0][0] = char(126);
		map[2][1] = char(92);
		map[2][2] = char(92);
		map[1][0] = char(254);
		map[1][2] = ' ';
	}
	mState = false;
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

bool CPEOPLE::isDead() {
	return mState;
}
int CPEOPLE::getX() { return mX; }
int CPEOPLE::getY() { return mY; }
char CPEOPLE::getType() { return type; }
void CPEOPLE:: killPeople() {
	mState = true;
}

/*bool CPEOPLE::isImpact(CVEHICLE* a[], int n) {
	for (int i = 0; i < n; ++i) {
		if (a[i] == NULL) continue;
		int dX = abs(a[i]->getX() - mX);
		int dY = abs(a[i]->getY() - mY);
		if (dX < 3 && dY < 3) {
			return true;
		}
	}
	return false;
}
bool CPEOPLE::isImpact(CANIMAL* b[], int n) {
	for (int i = 0; i < n; ++i) {
		if (b[i] == NULL) continue;
		int dX = abs(b[i]->getX() - mX);
		int dY = abs(b[i]->getY() - mY);
		if (dX < 3 && dY < 2) {
			return true;
		}
	}
	return false;
}*/
