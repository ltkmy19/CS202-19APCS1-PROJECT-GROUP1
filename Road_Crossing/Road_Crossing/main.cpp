
#include"Traffic_Light.h"
#include"Files.h"


int main() {
	resizeText(20, 20);

	FixConsoleWindow();
	hidecursor();
	

	mciSendString("play WeWillRockYou.mp3 repeat", NULL, 0, NULL);
	int character = 0;//male

	string Menu[4] = { "--New Game--", "--Load Game--", "--Setting--", "--Quit--" };
	int pointer = 0;
	int line = 2;
	while (true)
	{
		system("cls");
		LightMagenta();
		ifstream Reader("TextGraphic.txt");            

		string Art = getFileContents(Reader);     

		cout << Art << endl;              

		Reader.close();
		White();
		for (int i = 0; i < 4; ++i)
		{
			gotoXY(80, 3 + i + line);
			if (i == pointer)
			{
				Green();
				cout << Menu[i] << endl;
			}
			else
			{
				White();
				cout << Menu[i] << endl;
			}
		}
		White();
		while (true)
		{
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer -= 1;
				if (pointer == -1)
				{
					pointer = 2;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				pointer += 1;
				if (pointer == 4)
				{
					pointer = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				switch (pointer)
				{
				case 0:
				{
					system("cls");
					system("pause >nul");
					break;
				}
				case 1:
				{
					system("cls");
					system("pause >nul");

					break;
				}
				case 2:
				{

					break;
				}
				case 3:
				{
					return 0;
					break;
				}
				default:
				{
					break;
				}
				}
			}
				
			}
			Sleep(150);
		}
		system("pause >nul");

		return 0;
	}