#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <math.h>
#include <thread>
#include <fstream>
#include <string>
#include <map>
#include <Mmsystem.h>
#pragma comment(lib, "Winmm.lib")
using namespace std;

void resizeConsole(SHORT width, SHORT height);
void FixConsoleWindow();
void clrscr(void);
void gotoXY(SHORT x, SHORT y);
SHORT wherex();
SHORT wherey();
void setColor(WORD color);
void setBackgroundColor(WORD color);
void resizeText(int x, int y);
void setColorBGTextXY(SHORT x, SHORT y, WORD color, WORD background, LPSTR str, ...);
void Cursor(BOOL bVisible = TRUE, DWORD dwSize = 25);
void hidecursor();
void deleteRow(SHORT SStartPos, SHORT SNumberRow);
void ProgressBar();
void Black();
void Blue();
void Green();
void Cyan();
void Red();
void Magenta();
void Brown();
void LightGray();
void DarkGray();
void LightBlue();
void LightGreen();
void LightCyan(); 
void LightRed();
void LightMagenta();
void Yellow();
void White();

