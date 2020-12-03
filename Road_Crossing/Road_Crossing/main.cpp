
#include"Traffic_Light.h"
#include"Files.h"


int main() {
	resizeText(20, 20);

	FixConsoleWindow();
	hidecursor();
	

	mciSendString("play WeWillRockYou.mp3 repeat", NULL, 0, NULL);
	int character = 0;//male

	string Menu[6] = { "--New Game--", "--Load Game--", "--Sound--", "--Character--","--Tutorial--", "--Quit--" };
	int pointer = 0;
	int line = 2;
	while (true)
	{
		system("cls");
		LightMagenta();
		ifstream Reader("TextGraphic.txt");            

		string Art = getFileContents(Reader);     

		cout << Art << endl;     
		Green();
		gotoXY(70, 1);

		cout << "MENU" << endl;
		Reader.close();
		White();
		for (int i = 0; i < 6; ++i)
		{
			gotoXY(65, 3 + i);

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
					pointer = 5;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				pointer += 1;
				if (pointer == 6)
				{
					pointer = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				system("cls");

				switch (pointer)
				{
				case 0:
				{
					system("pause >nul");
					break;
				}
				case 1:
				{
					system("pause >nul");

					break;
				}
				case 2:
				{
					LightMagenta();
					ifstream Reader("TextGraphic.txt");

					string Art = getFileContents(Reader);

					cout << Art << endl;
					
					break;
				}
				case 3:
				{
					LightMagenta();
					ifstream Reader("TextGraphic.txt");

					string Art = getFileContents(Reader);

					cout << Art << endl;
					break;
				}
				case 4:
				{
					LightMagenta();
					ifstream Reader("TextGraphic.txt");

					string Art = getFileContents(Reader);

					cout << Art << endl;
					gotoXY(70, 5);

					cout << "Using w,a,s,d keys to move up, left, down, right.";
					cout << "There are 10 rounds for the game. Pass all of them to win a trophy.";
					break;
				}
				case 5:
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