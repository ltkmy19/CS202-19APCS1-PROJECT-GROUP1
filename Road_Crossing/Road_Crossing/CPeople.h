#include "Traffic_Light.h"
/*
MALE:
map[1][1] = char(219);
map[0][2] = '/';
map[2][0] = '/';
map[0][0] = char(92);
map[2][2] = char(92);
map[1][0] = char(254);
map[0][1] = ' ';
map[2][1]= ' ';
map[1][2]= ' ';

FEMALE:
map[1][1] = char(219);
map[0][2] = '/';
map[2][0] = char(126);
map[0][1] = '/';
map[0][0] = char(126);
map[2][1] = char(92);
map[2][2] = char(92);
map[1][0] = char(254);
map[1][2] = ' ';
*/
class CPEOPLE {
	int mX, mY;
	char map[3][3];
	bool mState; //true-> die, flase->alive
	char type;
public:
	CPEOPLE(int x, int y, char** _map, char type);
	void ReDraw(int x, int y, char type);
	void Up(int x);
	void Left(int x);
	void Right(int x);
	void Down(int x);
	/*bool isImpact(CVEHICLE* a[], int n);
	bool isImpact(CANIMAL* b[], int n);
	bool isFinish(int Finish);*/
	bool isDead();
	int getX();
	int getY();
	char getType();
	void killPeople();
	~CPEOPLE() {
		delete[]map;
	};
};
