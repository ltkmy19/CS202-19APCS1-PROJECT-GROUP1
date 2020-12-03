
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
	int sound = 1;
	
	while (true)
	{
		system("cls");
		LightMagenta();
		ifstream Reader("TextGraphic.txt");            

		string Art = getFileContents(Reader);     

		cout << Art << endl;     
		gotoXY(76, 5);
		Yellow();
		if (sound == 0) {
			cout << "OFF";
			mciSendString("pause  WeWillRockYou.mp3", NULL, 0, NULL);
		}
		else {
			cout << "ON";
			mciSendString("play  WeWillRockYou.mp3 repeat", NULL, 0, NULL);
		}
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

				switch (pointer)
				{
				case 0:
				{
					system("cls");
					//Game();
					system("pause >nul");
					break;
				}
				case 1:
				{
					system("cls");
					//LoadGame();
					system("pause >nul");

					break;
				}
				case 2:
				{	

					if (sound == 1) {
						sound = 0;
					}
					else {
						sound = 1;
					}
					
					break;

				}
				case 3:
				{
					system("cls");

					LightMagenta();
					ifstream Reader("TextGraphic.txt");

					string Art = getFileContents(Reader);

					cout << Art << endl;
					break;
				}
				case 4:
				{
					system("cls");

					gotoXY(70, 1);
					Green();
					cout << "TUTORIAL" << endl;
					int pos = 3;
					LightMagenta();
					ifstream Reader("TextGraphic.txt");
					string Art = getFileContents(Reader);
					cout << Art << endl;
					gotoXY(70, pos);
					LightGray();
					cout << "[w]: up"<<endl;
					gotoXY(70, pos+1);
					White();
					cout << "[a]: left" << endl;
					LightGray();
					gotoXY(70, pos + 2);
					cout << "[d]: right" << endl;
					White();
					gotoXY(70, pos + 3);
					cout << "[s]: down" << endl;
					gotoXY(60, pos + 5);
					Red();
					cout << "There are 10 rounds for the game."<<endl;
					break;
				}
				case 5:
				{
					system("cls");
					gotoXY(35, 10);
					LightMagenta();
					ifstream Reader("ByeBye.txt");
					string Art = getFileContents(Reader);
					cout << Art << endl;
					White();
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