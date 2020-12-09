#ifndef _CVEHICLE_H_
#define _CVEHICLE_H_

#include "Console.h"
#include "Files.h"

CVEHICLE(int x, int y);
void virtual Draw(int x, int y) = 0;
void Move(int, int);
bool IsDone();
int getX() { return mX; }
int getY() { return mY; }

#endif