#include"Traffic_Light.h"

//void Lights::RedLight(int x, int y) {
//	gotoXY(x, y - 1);
//	Red();
//	cout << char(219);
//	gotoXY(x, y);
//	DarkGray();
//	cout << char(219);
//	gotoXY(x, y + 1);
//	DarkGray();
//	cout << char(219);
//	White();
//
//}
//void Lights::GreenLight(int x, int y) {
//	gotoXY(x, y - 1);
//	DarkGray();
//	cout << char(219);
//	gotoXY(x, y);
//	DarkGray();
//	cout << char(219);
//	gotoXY(x, y + 1);
//	Green();
//	cout << char(219);
//	White();
//}
//
//void Lights::YellowLight(int x, int y) {
//	gotoXY(x, y - 1);
//	DarkGray();
//	cout << char(219);
//	gotoXY(x, y);
//	Yellow();
//	cout << char(219);
//	gotoXY(x, y + 1);
//	DarkGray();
//	cout << char(219);
//	White();
//}

void Lights::RedLight(int x, int y) {
	//gotoXY(x, y - 1);
	//Red();
	//cout << char(220); 
	//gotoXY(x, y);
	//DarkGray();
	//cout << char(223);
	//White();
	gotoXY(x, y);
	White();
	cout << char(186);
	gotoXY(x, y-1);
	Red();
	cout << char(219);
	gotoXY(x, y-2);
	DarkGray();
	cout << char(219);
	White();
}
void Lights::GreenLight(int x, int y) {
	//gotoXY(x, y - 1);
	//DarkGray();
	//cout << char(220);
	//gotoXY(x, y);
	//LightGreen();
	//cout << char(223); 
	//White();
	gotoXY(x, y );
	White();
	cout << char(186);
	gotoXY(x, y-1);
	DarkGray();
	cout << char(219);
	gotoXY(x, y-2);
	Green();
	cout << char(219);
	White();

}