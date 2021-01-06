#include "MultiThread.h"
int main() {
	resizeText(20, 20);

	FixConsoleWindow();
	hidecursor();


	mciSendString("play WeWillRockYou.mp3 repeat", NULL, 0, NULL);
	char character = '1';//male

	string Menu[6] = { "--New Game--", "--Load Game--", "--Sound--", "--Character--","--Tutorial--", "--Quit--" };
	int pointer = 0;
	int sound = 1;

	bool alive = true;
	int time = 1;
	char move = ' ';
	bool Is_move = true;
	CGAME* pp = new CGAME;

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

		gotoXY(89, 6);
		Yellow();
		if (character == '1') {
			cout << "MALE";
		}
		else if (character == '2') {
			cout << "FEMALE";
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
					char press;
					pp->startGame();
					thread game(RunGame, pp, Is_move, move,  time , alive);
					try {
						if (alive != true || alive != false) {
							throw 10;
						}
	
					while (alive == true) {
						system("cls");
						press = tolower(_getch());
						
								if (!pp->getPeople()->isDead()) {
									if (GetAsyncKeyState(VK_ESCAPE)) {
										pp->exitGame(game.native_handle());
										alive = false;
									}
									else if (press == 'p') {
										if (Is_move) {
											Is_move = false;
											pp->pauseGame(game.native_handle());
										}
										else {
											Is_move = true;
											pp->resumeGame(game.native_handle());
										}

									}
									else if (press == 'k') {
										if (!Is_move) {
											pp->saveGame();
										}
									}
									else if (press == 'l') {
										if (!Is_move) {
											pp->loadGame();
										}
									}
									else {
										if (Is_move) move = press;


									}
								}
								else {
									if (press == 'y') {
										pp->startGame();
									}
									else {
										pp->exitGame(game.native_handle());
										return 0;
									}
								}
							}

						}
						catch (int a) {

						}

					game.join();

					break;
				}
				case 1:  //Load Game
				{
					system("cls");
					gotoXY(45, 12);
					ifstream f; 
					int saveno = 0; 
					vector<FileSave*> File;
					f.open("SaveFile.txt");
					int level; string name;
					gotoXY(17, 15);
					if (f.fail()) {
						cout << "There is no save file!!";
					}
					else {
						cout << "Here are saved files: ";
						int line = 17;
						while (!f.eof()) {
							getline(f, name);
							f >> level;
							f.ignore();
							File[saveno] = new FileSave(level, name);
							gotoXY(17, line); cout << saveno + 1 << ". " << File[saveno]->getName() << " "
								<< File[saveno]->getLevel();
							saveno += 1; line += 1;
						}

						f.close();

						char type; 
						type = _getch();
						if (GetAsyncKeyState(VK_ESCAPE)!=true) {
							int a = type - '0';
							if (a <= saveno && a > 0) {
								int curLevel = File[a - 1]->getLevel();
								//pp->LoadLevel(curLevel);
							}
						}
						else continue;
					}
					char press;
					pp->startGame();
					thread game( RunGame, pp, Is_move, move,  time , alive );
					try {
						if (alive != true || alive != false) {
							throw 10;
						}
						while (alive == true) {
							system("cls");
							press = tolower(_getch());
							if (!pp->getPeople()->isDead()) {
								if (GetAsyncKeyState(VK_ESCAPE)) {
									pp->exitGame(game.native_handle());
									alive = false;
								}
								else if (press == 'p') {
									if (Is_move) {
										Is_move = false;
										pp->pauseGame(game.native_handle());
									}
									else {
										Is_move = true;
										pp->resumeGame(game.native_handle());
									}

								}
								else if (press == 'k') {
									if (!Is_move) {
										pp->saveGame();
									}
								}
								else if (press == 'l') {
									if (!Is_move) {
										pp->loadGame();
									}
								}
								else {
									if (Is_move) move = press;
								}
							}
							else {
								if (press == 'y') {
									pp->startGame();
								}
								else {
									pp->exitGame(game.native_handle());
									return 0;
								}
							}
						}
					}
					catch (int a) {

					}
					game.join();

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
					gotoXY(76, 1);
					Cyan();
					cout << "CHARACTER" << endl;
					int posx = 75;
					int posy = 4;
					White();
					CPEOPLE male(posx, posy, '1');
					male.ReDraw(posx, posy, '1');
					gotoXY(posx - 1, posy + 3);

					cout << "[1]";

					posx = 85;
					posy = 4;
					White();
					CPEOPLE female(posx, posy, '2');
					female.ReDraw(posx, posy, '2');
					gotoXY(posx - 1, posy + 3);
					cout << "[2]";
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
					character = _getch();
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
					cout << "[w]: up" << endl;
					gotoXY(80, pos + 1);
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
					cout << "There are 10 rounds for the game." << endl;
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
			_getch();
		}

		Sleep(150);
	}


	system("pause >nul");

	return 0;
}