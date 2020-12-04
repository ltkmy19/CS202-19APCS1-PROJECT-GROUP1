#include"Traffic_Light.h"
#include"Files.h"

int main() {
	resizeText(20, 20);

	FixConsoleWindow();
	hidecursor();
	

	mciSendString("play WeWillRockYou.mp3 repeat", NULL, 0, NULL);
	char character = '1';//male

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
		gotoXY(85, 5);
		Yellow();
		if (sound == 0) {
			cout << "OFF";
			mciSendString("pause  WeWillRockYou.mp3", NULL, 0, NULL);
		}
		else {
			cout << "ON";
			mciSendString("play  WeWillRockYou.mp3 repeat", NULL, 0, NULL);
		}

		gotoXY(90, 6);
		Yellow();
		if (character == '1') {
			cout << "MALE";
		}
		else if (character == '2') {
			cout << "FEMALE";
		}
		else {
			cout << character;
		}
		Cyan();
		gotoXY(80, 1);
		cout << "MENU" << endl;
		Reader.close();
		White();
		for (int i = 0; i < 6; ++i)
		{
			gotoXY(75, 3 + i);

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
				case 0: //New Game
				{
					system("cls");
					ProgressBar();
					system("cls");
					gotoXY(45, 12);
					cout << "Surprise!!!" << endl;
					//Game();
					system("pause >nul");
					break;
				}
				case 1:  //Load Game
				{
					system("cls");
					gotoXY(45, 12);

					cout << "Surprise!!!" << endl;
					//LoadGame();
					system("pause >nul");

					break;
				}
				case 2:  //Sound
				{	

					if (sound == 1) {
						sound = 0;
					}
					else {
						sound = 1;
					}
					
					break;

				}
				case 3:   //Character
				{
					system("cls");

					LightMagenta();
					ifstream Reader("TextGraphic.txt");

					string Art = getFileContents(Reader);

					cout << Art << endl;
					gotoXY(80, 1);
					Cyan();
					cout << "CHARACTER" << endl;
					int posx = 75;
					int posy = 4;
					White();
					gotoXY(posx, posy);
					char map[3][3];
					map[1][1] = char(219);
					map[0][2] = '/';
					map[2][0] = '/';
					map[0][0] = char(92);
					map[2][2] = char(92);
					map[1][0] = char(254);
					gotoXY(posx, posy);
					cout << map[1][1];
					gotoXY(posx - 1, posy + 1);
					cout << map[0][2];
					gotoXY(posx + 1, posy - 1);
					cout << map[2][0];
					gotoXY(posx - 1, posy - 1);
					cout << map[0][0];
					gotoXY(posx + 1, posy + 1);
					cout << map[2][2];
					gotoXY(posx, posy - 1);
					cout << map[1][0];
					gotoXY(posx-1, posy +3);
					cout << "[1]";

					posx = 85;
					posy = 4;
					White();
					gotoXY(posx, posy);
					map[1][1] = char(219);
					map[0][2] = '/';
					map[2][0] = '/';
					map[0][0] = char(92);
					map[2][2] = char(92);
					map[1][0] = char(254);
					gotoXY(posx, posy);
					cout << map[1][1];
					gotoXY(posx - 1, posy + 1);
					cout << map[0][2];
					gotoXY(posx + 1, posy - 1);
					cout << map[2][0];
					gotoXY(posx - 1, posy - 1);
					cout << map[0][0];
					gotoXY(posx + 1, posy + 1);
					cout << map[2][2];
					gotoXY(posx, posy - 1);
					cout << map[1][0];
					gotoXY(posx - 1, posy + 3);
					cout << "[2]";
					character= _getch();
					
					break;
				}
				case 4:  //Tutorial
				{
					system("cls");
					gotoXY(80, 1);
					Cyan();
					cout << "TUTORIAL" << endl;
					int pos = 3;
					LightMagenta();
					ifstream Reader("TextGraphic.txt");
					string Art = getFileContents(Reader);
					cout << Art << endl;
					gotoXY(80, pos);
					LightGray();
					cout << "[w]: up"<<endl;
					gotoXY(80, pos+1);
					White();
					cout << "[a]: left" << endl;
					LightGray();
					gotoXY(80, pos + 2);
					cout << "[d]: right" << endl;
					White();
					gotoXY(80, pos + 3);
					cout << "[s]: down" << endl;
					gotoXY(70, pos + 5);
					Red();
					cout << "There are 10 rounds for the game."<<endl;
					break;
				}
				case 5:   //Quit
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