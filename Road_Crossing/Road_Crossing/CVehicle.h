#ifndef _CVEHICLE_H_
#define _CVEHICLE_H_

class CVEHICLE
{
protected:
	int x, y, Way;
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
	CTRUCK(int tmpX, int tmpY);
	void Draw(int tmpX, int tmpY);
};

class CCAR : public CVEHICLE
{
private:
public:
	CCAR(int tmpX, int tmpY);
	void Draw(int tmpX, int tmpY);
};

#endif