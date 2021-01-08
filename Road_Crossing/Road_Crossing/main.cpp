#include"MultiThread.h"
using namespace std;

int main() {
	resizeText(20, 20);

	FixConsoleWindow();
	hidecursor();


	mciSendString("play welcome.wav", NULL, 0, NULL);
	char character = '1';//male
	string Menu[6] = { "--New Game--", "--Load Game--", "--Sound--", "--Character--","--Tutorial--", "--Quit--" };
	int pointer = 0;
	int sound = 1;
	bool alive = true;
	int ti = Stoptime;
	bool Is_move = true;
	CGAME* pp;
	char MOVE;
	bool enter = GetAsyncKeyState(VK_RETURN);
	bool Is_Enter = false;
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
			mciSendString("pause  welcome.wav", NULL, 0, NULL);
		}
		else {
			cout << "ON";
			mciSendString("play  welcome.wav", NULL, 0, NULL);
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
			/*if (Is_Enter == false) {
				enter = GetAsyncKeyState(VK_RETURN);
			}*/
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer -= 1;
				if (pointer == -1)
				{
					pointer = 5;
				}
				Is_Enter = false;
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				pointer += 1;
				if (pointer == 6)
				{
					pointer = 0;
				}
				Is_Enter = false;
				break;
			}
			//&& Is_Enter == false
			else if (GetAsyncKeyState(VK_RETURN))
			{

				switch (pointer)
				{
				case 0: //New Game
				{
					mciSendString("stop  welcome.wav", NULL, 0, NULL);
					system("cls");
					ProgressBar();
					system("cls");
					char press;
					alive = true;
					Is_move = true;
					MOVE = ' ';
					ti = Stoptime;
					pp = new CGAME(character);

					pp->loadLevel(1);
					mciSendString("play  ingame.wav", NULL, 0, NULL);
					pp->startGame();
					thread game{ RunGame, ref(pp),ref(Is_move), ref(ti), ref(alive), ref(MOVE) };
					while (alive == true) {
						press = _getch();
						press = tolower(press);
						mciSendString("pause  ingame.wav", NULL, 0, NULL);
						if (!pp->getPeople()->isDead()) {
							if (GetAsyncKeyState(VK_ESCAPE)) {
								pp->exitGame(game.native_handle());
								alive = false;
								mciSendString("stop ingame.wav", NULL, 0, NULL);

							}
							else if (press == 'p') {
								if (Is_move) {
									Is_move = false;
									pp->pauseGame(game.native_handle());
								}
								else {
									Is_move = true;
									pp->resumeGame(game.native_handle());
									mciSendString("play  ingame.wav", NULL, 0, NULL);
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
								if (alive && Is_move) {
									mciSendString("play  ingame.wav", NULL, 0, NULL);
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
					Is_Enter = false;
					break;
				}
				case 1:  //Load Game
				{
					system("cls");
					LightMagenta();
					ifstream Reader("TextGraphic.txt");
					string Art = getFileContents(Reader);
					cout << Art << endl;
					gotoXY(80, 1);
					Cyan();
					cout << "SCOREBOARD" << endl;
					gotoXY(80, 3);
					Red();
					string Filename;
					cout << "Input File name: ";
					gotoXY(80, 4);
					White();
					getline(cin, Filename);
					system("cls");
					gotoXY(80, 1);
					Cyan();
					cout << "SCOREBOARD" << endl;
					int pos = 3;
					LightMagenta();
					cout << Art << endl;
					gotoXY(80, pos);
					ifstream f;
					int saveno = 0;
					vector<FileSave*> File;
					FileSave* Filetemp;
					f.open(Filename);
					int level; string name; char cha;
					if (!f.fail()) {
						while (!f.eof()) {
							f >> cha;
							f.ignore();
							getline(f, name);
							f >> level;
							f.ignore();
							Filetemp = new FileSave(level, name, cha);
							File.push_back(Filetemp);
							saveno++;
							White();
						}
						f.close();

						for (int i = 0; i < saveno - 1; i++) {
							gotoXY(80, pos);
							LightGray();
							cout << i + 1 << ". " << File[i]->getName() << " " << File[i]->getLevel() << " ";
							if (File[i]->getCharacter() == '2') {
								cout << "FEMALE";
							}
							else {
								cout << "MALE";
							}

							pos++;
						}
						int choose;
						choose = _getch();
						choose -= '0';
						if (GetAsyncKeyState(VK_ESCAPE) != true) {

							if (choose <= saveno && choose > 0) {
								level = File[choose - 1]->getLevel();
								cha = File[choose - 1]->getCharacter();
								character = cha;
							}
						}
						else {
							continue;
						}
					}
					else {
						f.close();
						level = 1;

					}
					system("cls");
					pp = new CGAME(character);
					pp->loadLevel(level);
					char press;
					alive = true;
					Is_move = true;
					MOVE = ' ';
					ti = Stoptime;
					mciSendString("stop  welcome.wav", NULL, 0, NULL);
					mciSendString("play  ingame.wav", NULL, 0, NULL);
					pp->startGame();
					thread game(RunGame, ref(pp), ref(Is_move), ref(ti), ref(alive), ref(MOVE));
					while (alive == true) {
						press = tolower(_getch());
						if (!pp->getPeople()->isDead()) {
							if (GetAsyncKeyState(VK_ESCAPE)) {
								pp->exitGame(game.native_handle());
								alive = false;
								mciSendString("stop ingame.wav", NULL, 0, NULL);
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
					Is_Enter = true;
					game.join();
					enter = false;
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
					Is_Enter = false;
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
					_getch();
					Is_Enter = false;

					break;

				}
				case 5:   //Quit
				{
					system("cls");
					LightMagenta();
					ifstream Reader("ByeBye.txt");
					string Art = getFileContents(Reader);
					cout << Art << endl;
					White();

					return 0;
					Is_Enter = false;

					break;
				}

				default:
				{

					break;
				}

				}
				//break;

			}

			_getch();


		}

		Sleep(150);
	}

	delete pp;
	system("pause >nul");

	return 0;
}