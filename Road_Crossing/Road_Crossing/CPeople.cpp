#include "CPeople.h"
#include "CGame.h"

CPEOPLE::CPEOPLE(int x, int y, char type) {
	posX = x;
	posY = y;
	this->type = type;
	if (type == '1') {
		people[1][1] = char(219);
		people[0][2] = '/';
		people[2][0] = '/';
		people[0][0] = char(92);
		people[2][2] = char(92);
		people[1][0] = char(254);
		people[0][1] = ' ';
		people[2][1] = ' ';
		people[1][2] = ' ';
	}
	else {
		people[1][1] = char(219);
		people[0][2] = '/';
		people[2][0] = char(126);
		people[0][1] = '/';
		people[0][0] = char(126);
		people[2][1] = char(92);
		people[2][2] = char(92);
		people[1][0] = char(254);
		people[1][2] = ' ';
	}
	Draw(x, y, type);
	mState = false;
}
void CPEOPLE::Draw(int x, int y, char type) {
	if (type == '1') {
		gotoXY(x, y);
		Brown();
		cout << people[1][1];
		White();
		gotoXY(x - 1, y + 1);
		cout << people[0][2];
		gotoXY(x + 1, y - 1);
		cout << people[2][0];
		gotoXY(x - 1, y - 1);
		cout << people[0][0];
		gotoXY(x + 1, y + 1);
		cout << people[2][2];
		gotoXY(x, y - 1);
		cout << people[1][0];
	}
	else {
		gotoXY(x, y);
		LightMagenta();
		cout << people[1][1];
		White();
		gotoXY(x - 1, y + 1);
		cout << people[0][2];
		gotoXY(x - 1, y);
		cout << people[0][1];
		gotoXY(x + 1, y);
		cout << people[2][1];
		gotoXY(x + 1, y - 1);
		cout << people[2][0];
		gotoXY(x - 1, y - 1);
		cout << people[0][0];
		gotoXY(x + 1, y + 1);
		cout << people[2][2];
		gotoXY(x, y - 1);
		cout << people[1][0];
	}

}

void CPEOPLE:: Up(int x) {
	LightCyan();
	gotoXY(posX, posY);
	cout << ' ';
	gotoXY(posX - 1, posY + 1);
	cout << '_';
	gotoXY(posX + 1, posY - 1);
	cout << ' ';
	gotoXY(posX - 1, posY - 1);
	cout << ' ';
	gotoXY(posX + 1, posY + 1);
	cout << '_';
	gotoXY(posX, posY - 1);
	cout << ' ';
	gotoXY(posX, posY + 1);
	cout << '_';
	gotoXY(posX + 1, posY );
	cout << ' ';
	gotoXY(posX - 1, posY);
	cout << ' ';
	posY -= x;
	Draw(posX, posY, type);
	PlaySound(TEXT("popsound.wav"), NULL, SND_ASYNC);
}

void CPEOPLE::Down(int x) {
	LightCyan();
	gotoXY(posX, posY);
	cout << ' ';
	gotoXY(posX - 1, posY + 1);
	cout << '_';
	gotoXY(posX + 1, posY - 1);
	cout << ' ';
	gotoXY(posX - 1, posY - 1);
	cout << ' ';
	gotoXY(posX + 1, posY + 1);
	cout << '_';
	gotoXY(posX, posY - 1);
	cout << ' ';
	gotoXY(posX, posY + 1);
	cout << '_';
	gotoXY(posX + 1, posY);
	cout << ' ';
	gotoXY(posX - 1, posY);
	cout << ' ';
	posY += x;
	Draw(posX, posY, type);
	PlaySound(TEXT("popsound.wav"), NULL, SND_ASYNC);
}
void CPEOPLE:: Left(int x) {
	LightCyan();
	gotoXY(posX, posY);
	cout << ' ';
	gotoXY(posX - 1, posY + 1);
	cout << '_';
	gotoXY(posX + 1, posY - 1);
	cout << ' ';
	gotoXY(posX - 1, posY - 1);
	cout << ' ';
	gotoXY(posX + 1, posY + 1);
	cout << '_';
	gotoXY(posX, posY - 1);
	cout << ' ';
	gotoXY(posX, posY + 1);
	cout << '_';
	gotoXY(posX + 1, posY);
	cout << ' ';
	gotoXY(posX - 1, posY);
	cout << ' ';
	posX -= x;
	Draw(posX, posY, type);
	PlaySound(TEXT("popsound.wav"), NULL, SND_ASYNC);
}
void CPEOPLE:: Right(int x) {
	LightCyan();
	gotoXY(posX, posY);
	cout << ' ';
	gotoXY(posX - 1, posY + 1);
	cout << '_';
	gotoXY(posX + 1, posY - 1);
	cout << ' ';
	gotoXY(posX - 1, posY - 1);
	cout << ' ';
	gotoXY(posX + 1, posY + 1);
	cout << '_';
	gotoXY(posX, posY - 1);
	cout << ' ';
	gotoXY(posX, posY + 1);
	cout << '_';
	gotoXY(posX + 1, posY);
	cout << ' ';
	gotoXY(posX - 1, posY);
	cout << ' ';
	posX += x;
	Draw(posX, posY, type);
	PlaySound(TEXT("popsound.wav"), NULL, SND_ASYNC);
}

bool CPEOPLE::isDead() {
	return mState;
}
int CPEOPLE::getX() { 
	return posX; 
}
int CPEOPLE::getY() { 
	return posY; 
}
char CPEOPLE::getType() { 
	return type; 
}
void CPEOPLE:: killPeople() {
	mState = true;
}

//bool CPEOPLE::ISCrashed(vector<CVEHICLE*> a, int n) {
//	for (int i = 0; i < n; ++i) {
//		if (a[i] == NULL) {
//			continue;
//		}
//		int dX = abs(a[i]->getX() - posX);
//		int dY = abs(a[i]->getY() - posY);
//		if (dX < 3 && dY < 3) {
//			return true;
//		}
//	}
//	return false;
//}
//bool CPEOPLE::ISCrashed(vector<CANIMAL*> b, int n) {
//	for (int i = 0; i < n; ++i) {
//		if (b[i] == NULL) continue;
//		int dX = abs(b[i]->getX() - posX);
//		int dY = abs(b[i]->getY() - posY);
//		if (dX < 3 && dY < 2) {
//			return true;
//		}
//	}
//	return false;
//}

bool CPEOPLE::ISCrashedCar(CVEHICLE** a, int n) {
	for (int i = 0; i < n; ++i) {
		if (a[i] == NULL) {
			continue;
		}
		int dX = abs(a[i]->getX() - posX);
		int dY = abs(a[i]->getY() - posY);
		if (dX < 3 && dY < 3) {
			mciSendString("play  car.wav", NULL, 0, NULL);
			return true;
		}
	}
	return false;
}
bool CPEOPLE::ISCrashedTruck(CVEHICLE** b, int n) {
	for (int i = 0; i < n; ++i) {
		if (b[i] == NULL) {
			continue;
		}
		int dX = abs(b[i]->getX() - posX);
		int dY = abs(b[i]->getY() - posY);
		if (dX < 3 && dY < 3) {
			mciSendString("play  truck.wav", NULL, 0, NULL);
			return true;
		}
	}
	return false;
}
bool CPEOPLE::ISCrashedDinausor(CANIMAL** a, int n) {
	for (int i = 0; i < n; ++i) {
		if (a[i] == NULL) continue;
		int dX = abs(a[i]->getX() - posX);
		int dY = abs(a[i]->getY() - posY);
		if (dX < 3 && dY < 2) {
			mciSendString("play  dinosaur.wav", NULL, 0, NULL);
			return true;
		}
	}
	return false;
}
bool CPEOPLE::ISCrashedBird(CANIMAL** b, int n) {
	for (int i = 0; i < n; ++i) {
		if (b[i] == NULL) continue;
		int dX = abs(b[i]->getX() - posX);
		int dY = abs(b[i]->getY() - posY);
		if (dX < 3 && dY < 2) {
			mciSendString("play  bird.wav", NULL, 0, NULL);
			return true;
		}
	}
	return false;
}

bool CPEOPLE::isFinish(int Finish) {
	if (posY == Finish - 1)
		return true;
	return false;
}