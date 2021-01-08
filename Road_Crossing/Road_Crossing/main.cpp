#include"MultiThread.h"
using namespace std;

int main() {
	resizeText(20, 20);

	FixConsoleWindow();
	hidecursor();


	mciSendString("play welcome.mp3 repeat", NULL, 0, NULL);
	char character = '1';//male

	string Menu[6] = { "--New Game--", "--Load Game--", "--Sound--", "--Character--","--Tutorial--", "--Quit--" };
	int pointer = 0;
	int sound = 1;

	bool alive = true;
	int ti = Stoptime;
	bool Is_move = true;
	CGAME* pp;
	char MOVE;

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
			mciSendString("pause  welcome.mp3", NULL, 0, NULL);
		}
		else {
			cout << "ON";
			mciSendString("play  welcome.mp3 repeat", NULL, 0, NULL);
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
					mciSendString("stop  welcome.mp3", NULL, 0, NULL);
					system("cls");
					ProgressBar();
					system("cls");
					char press;
					alive = true;
					Is_move = true;
					MOVE = ' ';
					ti = Stoptime;
					pp = new CGAME(character);

				//	pp->loadLevel(1);
					mciSendString("play  ingame.wav", NULL, 0, NULL);
					pp->startGame();
					thread game{ RunGame, ref(pp),ref(Is_move), ref(ti), ref(alive), ref(MOVE) };
					while (alive == true) {
						press = _getch();
						press = tolower(press);
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
							else if (press == 'l') {
								if (!Is_move) {
									pp->saveGame();
								}
							}
							else if (press == 't') {
								if (!Is_move) {
									pp->loadGame();
								}
							}
							else {
								if (Is_move) {
									MOVE = press;
								}


							}
						}
						else {
							if (press == 'y') {
								pp->startGame();
							}
							else {
								pp->exitGame(game.native_handle());
								delete pp;
								return 0;
							}
						}
					}

					game.join();

					break;
				}
				case 1:  //Load Game
				{
					system("cls");
					gotoXY(80, 1);
					Cyan();
					cout << "SCOREBOARD" << endl;
					int pos = 3;
					LightMagenta();
					ifstream Reader("TextGraphic.txt");
					string Art = getFileContents(Reader);
					cout << Art << endl;
					gotoXY(80, pos);
					ifstream f;
					int saveno = 0;
					vector<FileSave*> File;
					FileSave* Filetemp;
					f.open("SaveFile.txt");
					int level; string name; int cha;
					if (f.fail()) {
						f.close();
							//	pp->loadLevel(1);
					}
					else {
						while (!f.eof()) {
						
							f >> cha;
							f.ignore();
							getline(f, name);
							f >> level;
							f.ignore();
							Filetemp= new FileSave(level, name);
							File.push_back(Filetemp);
							saveno ++ ; 
							White();
						}
						f.close();

						for (int i = 0; i < saveno; i++) {
							gotoXY(80, pos);
							LightGray();
							cout << i + 1 << ". " << File[i]->getName() << " " << File[i]->getLevel();
							pos++;
						}
						int choose;
						choose = _getch();
						choose -= '0';
						if (GetAsyncKeyState(VK_ESCAPE) != true) {
							
							if (choose <= saveno && choose > 0) {
								level = File[choose-1]->getLevel();
					
							//	cha = File[choose - 1]->getcharater();
								//	pp->loadLevel(curLevel);
								character = cha;
							}
						}
						else {
							continue;
						}
					}
					system("cls");
					pp = new CGAME(character);
					char press;
					alive = true;
					Is_move = true;
					MOVE = ' ';
					ti = Stoptime;
					mciSendString("stop  welcome.mp3", NULL, 0, NULL);
					mciSendString("play  ingame.wav", NULL, 0, NULL);
					pp->startGame();
					thread game(RunGame, ref(pp), ref(Is_move), ref(ti), ref(alive), ref(MOVE));
					while (alive == true) {
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
								if (Is_move) {
									MOVE = press;
								}
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
						male.Draw(posx, posy, '1');
						gotoXY(posx - 1, posy + 3);

						cout << "[1]";

						posx = 85;
						posy = 4;
						White();
						CPEOPLE female(posx, posy, '2');
						female.Draw(posx, posy, '2');
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

	delete pp;
	system("pause >nul");

	return 0;
}