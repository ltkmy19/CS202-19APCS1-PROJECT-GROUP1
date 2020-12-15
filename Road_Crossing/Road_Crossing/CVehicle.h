#include "Console.h"

class CVEHICLE
{
private:
	int x, y;
public:
	CVEHICLE(int tmpX, int tmpY);
	void virtual Draw(int tmpX, int tmpY) = 0;
	void Move(int, int);
	bool IsDone();
	int getX() { return x; }
	int getY() { return y; }
};

class CTRUCK: public CVEHICLE
{
private:
public:
	CTRUCK(int x, int y);
	void Draw(int x, int y);
};

class CCAR : public CVEHICLE
{
private:
public:
	CCAR(int x, int y);
	void Draw(int x, int y);
};