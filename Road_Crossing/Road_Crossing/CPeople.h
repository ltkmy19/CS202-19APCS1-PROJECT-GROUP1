#ifndef _CPEOPLE_H_
#define _CPEOPLE_H_

#include <vector>
#include "CAnimal.h"
#include "CVehicle.h"
using namespace std;

class CPEOPLE {
	int posX, posY;
	char people[3][3];
	bool mState; //true-> die, flase->alive
	char type;
public:
	CPEOPLE(int x, int y, char type);
	void ReDraw(int x, int y, char type);
	void Up(int x);
	void Left(int x);
	void Right(int x);
	void Down(int x);
	bool ISCrashed(vector<CCAR*> a, int n);
	bool ISCrashed(vector<CTRUCK*> b, int n);
	bool ISCrashed(vector<CDINAUSOR*> a, int n);
	bool ISCrashed(vector<CBIRD*> b, int n);
	bool isFinish(int Finish);
	bool isDead();
	int getX();
	int getY();
	char getType();
	void killPeople();
	~CPEOPLE() {
		
	};
};

#endif