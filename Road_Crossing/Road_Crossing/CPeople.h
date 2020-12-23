#include "Traffic_Light.h"

class CPEOPLE {
	int mX, mY;
	char map[3][3];
	bool mState; //true-> die, flase->alive
	char type;
public:
	CPEOPLE(int x, int y, char type);
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
		
	};
};
