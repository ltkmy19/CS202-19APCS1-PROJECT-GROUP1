
#include "Console.h"



HANDLE hConsoleOutput;
HANDLE hConsoleInput;
void FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

// Resize the Console Window
void resizeConsole(SHORT width, SHORT height)
{


	COORD crd = {width, height};
	SMALL_RECT rec = {0, 0, width - 1, height - 1};
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(hConsoleOutput, TRUE, &rec);
	SetConsoleScreenBufferSize(hConsoleOutput, crd);
}

// Delete Window data.
void clrscr(void)
{
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	COORD Home = {0, 0};
	DWORD dummy;

	hConsoleOutput = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	FillConsoleOutputCharacter(hConsoleOutput, ' ', screen_buffer_info.dwSize.X * screen_buffer_info.dwSize.Y, Home, &dummy);
	screen_buffer_info.dwCursorPosition.X = 0;
	screen_buffer_info.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOutput, screen_buffer_info.dwCursorPosition);
}

// Move the cursor.
void gotoXY(SHORT x, SHORT y)
{
	COORD Cursor_an_Pos = {x, y};
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

// Show the x position.
SHORT wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO coninfo;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOutput, &coninfo);
	return coninfo.dwCursorPosition.X;
}

// Show the y position.
SHORT wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO coninfo;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOutput, &coninfo);
	return coninfo.dwCursorPosition.Y;
}

// Color Window;
void setColor(WORD color)
{
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

// Color background
void setBackgroundColor(WORD color)
{
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;		  
	wAttributes &= 0xff0f; 
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

 void resizeText(int x, int y)
 {
 	PCONSOLE_FONT_INFOEX font = new CONSOLE_FONT_INFOEX();
 	font->cbSize = sizeof(CONSOLE_FONT_INFOEX);
 	GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, font);
 	font->dwFontSize.X = x;
 	font->dwFontSize.Y = y;
 	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, font);
 }
WORD textattr()
{
	CONSOLE_SCREEN_BUFFER_INFO ConsoleInfo;
	GetConsoleScreenBufferInfo(hConsoleOutput, &ConsoleInfo);
	return ConsoleInfo.wAttributes;
}
void hidecursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void resettextattr()
{
	DWORD Mau_Mac_Dinh = textattr();
	SetConsoleTextAttribute(hConsoleOutput, Mau_Mac_Dinh);
}

// Ham in mau chu va thay doi mai nen hien thi theo vi tri x, y.
void setColorBGTextXY(SHORT x, SHORT y, WORD color, WORD background, LPSTR str, ...)
{
	gotoXY(x, y);
	setBackgroundColor(background);
	setColor(color);

	va_list args;
	va_start(args, str);
	vprintf(str, args);
	va_end(args);

	resettextattr();
	//setColor(7);
}

void Cursor(BOOL bVisible, DWORD dwSize)
{
	CONSOLE_CURSOR_INFO ConsoleCursorInfo;
	ConsoleCursorInfo.bVisible = bVisible;
	ConsoleCursorInfo.dwSize = dwSize; // Phan tram bao trum o cua con tro chuot
	SetConsoleCursorInfo(hConsoleOutput, &ConsoleCursorInfo);
}

// Delete number of rows, SStartPos - Row start; SNumberRow: Number of rows.
void deleteRow(SHORT SStartPos, SHORT SNumberRow)
{
	CONSOLE_SCREEN_BUFFER_INFO ConsoleInfo;
	COORD Pos = {0, SStartPos};
	DWORD Tmp;
	GetConsoleScreenBufferInfo(hConsoleOutput, &ConsoleInfo);
	FillConsoleOutputCharacter(hConsoleOutput, ' ', ConsoleInfo.dwSize.X * SNumberRow, Pos, &Tmp);
	FillConsoleOutputAttribute(hConsoleOutput, 15, ConsoleInfo.dwSize.X * SNumberRow, Pos, &Tmp);
	SetConsoleCursorPosition(hConsoleOutput, Pos);
}
void ProgressBar() {
	float progress = 0.0;
	while (progress < 1.0) {
		Sleep(100);
		int barWidth = 70;
		gotoXY(1, 12);
		cout << progress * 100 << "%" << endl;
		cout << "[";
		int pos = barWidth * progress;
		for (int i = 0; i < barWidth; ++i) {
			if (i < pos) {
				cout << "=";
			}
			else if (i == pos) {
				cout << ">";
			}
			else {
				cout << " ";
			}
		}
		cout << "] " << 100 << " %\r";
		progress += 0.16;
	}
}
//Black | 0
//Blue | 1
//Green | 2
//Cyan | 3
//Red | 4
//Magenta | 5
//Brown | 6
//Light Gray | 7
//Dark Gray | 8
//Light Blue | 9agenta()
//Light Green | 10
//Light Cyan | 11
//Light Red | 12
//Light Magenta | 13
//Yellow | 14
//White | 15
void Black()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
}
void Blue()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
}
void Green()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
}
void Cyan()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
}
void Red()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
}
void Magenta()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
}
void Brown()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
}
void LightGray()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
void DarkGray()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
}
void LightBlue()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
}
void LightGreen()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
}
void LightCyan()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
}
void LightRed()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
}
void LightMagenta()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
}
void Yellow()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
}
void White()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}