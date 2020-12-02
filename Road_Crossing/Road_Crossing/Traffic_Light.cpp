#include"Traffic_Light.h"

void Lights::RedLight(int x, int y) {
	gotoXY(x, y - 1);
	Red();
	cout << char(220);
	gotoXY(x, y);
	DarkGray();
	cout << char(223);
	White();

}
void Lights::GreenLight(int x, int y) {
	gotoXY(x, y - 1);
	DarkGray();
	cout << char(220);
	gotoXY(x, y);
	Green();
	cout << char(223);
	White();
}