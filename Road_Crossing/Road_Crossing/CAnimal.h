#include "Console.h"
#include "CGame.h"

class CANIMAL {
protected:
	int x, y, Way;
public:
	CANIMAL(int tmpX, int tmpY);
	void virtual Draw(int tmpX, int tmpY) = 0;
	void Move(int, int);
	bool IsDone();
	int getX() { return x; }
	int getY() { return y; }
};

class CDINAUSOR : public CANIMAL {
public:
	CDINAUSOR(int tmpX, int tmpY);
	void Draw(int tmpX, int tmpY);
};

class CBIRD : public CANIMAL {
public:
	CBIRD(int tmpX, int tmpY);
	void Draw(int tmpX, int tmpY);
};

