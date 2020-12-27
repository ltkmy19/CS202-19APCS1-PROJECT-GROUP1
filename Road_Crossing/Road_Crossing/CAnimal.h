#include "Console.h"

class CANIMAL {
protected:
	int mX, mY, Way;
public:
	CANIMAL(int x, int y);
	void virtual Draw(int x, int y) = 0;
	void Move(int, int);
	bool IsDone();
	int getX() { return mX; }
	int getY() { return mY; }
};

class CDINAUSOR : public CANIMAL {
public:
	CDINAUSOR(int x, int y);
	void Draw(int x, int y);
};

class CBIRD : public CANIMAL {
public:
	CBIRD(int x, int y);
	void Draw(int x, int y);
};

