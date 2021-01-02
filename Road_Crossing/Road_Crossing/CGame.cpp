#include "CGame.h"
#include <fstream>
using namespace std;

CGame::CGAME(){

}

void CGAME::drawGame() {
    LightMagenta();
    gotoXY(0, 0); cout << (char)218; for (int i = 1; i < WIDTH; i++) { cout << (char)196; } cout << (char)191;
    gotoXY(0, 1); for (int i = 2; i < HEIGHT; i++) { cout << (char)179; gotoXY(0, i); }
    gotoXY(0, HEIGHT - 1); cout << (char)192; for (int i = 1; i < WIDTH; i++) { cout << (char)196; }
    gotoXY(WIDTH, 1); for (int i = 2; i < HEIGHT; i++) { cout << (char)179; gotoXY(WIDTH, i); } cout << (char)217;

    int W = WIDTH + 8;
    int H = HEIGHT - 10;
    gotoXY(W, 2); cout << (char)218; for (int i = W+1; i < W+30;i++) { cout << (char)196; } cout << (char)191;
    gotoXY(W, 3); for (int i = 4; i < H; i++) { cout << (char)179; gotoXY(W, i); }
    gotoXY(W, H-1); cout << (char)192; for (int i = W+1; i < W+30; i++) { cout << (char)196; }
    gotoXY(W+30, 3); for (int i = 3; i < H; i++) { cout << (char)179; gotoXY(W+30, i); } cout << (char)217;

    LightCyan();
    gotoXY(W + 1, 4); cout << "WELCOME TO CROSSING ROAD! ^_^";
    gotoXY(W + 7, 6); cout << "press ESC to exit ";
    gotoXY(W + 5, 8); cout << "Level: 1";
    gotoXY(W + 5, 10); cout << "P: Pause/Resume ";
    gotoXY(W + 6, 12); cout << "Please pause before: ";
    gotoXY(W + 5, 14); cout << "K: Load game ";
    gotoXY(W + 5, 16); cout << "S: Save game ";
}

CGAME::~CGAME(){
    delete[] axh;
    delete[] axt;
    delete[] akl;
    delete[] ac;
    delete[] lv;
}

CPEOPLE CGAME::getPeople(){
    return cn;
}

vector <CVEHICLE*> CGAME::getVehicle(){
    int c = lv[curLevel-1]->AmountOfCar();
    int t = lv[curLevel-1]->AmountOfTruck();;
    vector<CVEHICLE*>tmp;
    for(int i = 0;i < c;i++){
        tmp.push_back(&(axh[i]));
    }
    for(int j = 0;j < t;j++){
        tmp.push_back(&(axt[j]));
    }
    return tmp;
}

vector <CANIMAL*> CGAME::getAnimal(){
    int d = lv[curLevel-1]->AmountOfDinasour();
    int b = lv[curLevel-1]->AmountOfBird();
    vector<CANIMAL*>tmp;
    for(int i = 0;i < d;i++){
        tmp.push_back(&(akl[i]));
    }
    for(int j = 0;j < b;j++){
        tmp.push_back(&(ac[j]));
    }
    return tmp;
}

void CGAME::resetGame()
void CGAME::exitGame(HANDLE)
void CGAME::startGame()


void CGAME::loadGame() {
	Clean();
	ifstream fin;
	int numberOfSave = 0;
	int W = WIDTH + 6;
	int H = HEIGHT - 5;
	int level = 0, line = H;
	string name = "";
	FileSave* tmp = nullptr;
	fin.open("SaveFiles.txt");
	if (!fin.is_open()) {
		GotoXY(W + 2, H + 4); cout << "Can not open file!";
		Sleep(500);
		Clean();
		return;
	}
	else {
		if (fin.eof()) cout << "There is no save file!" << endl;
		else {
			while (!fin.eof()) {
				fin >> level;
				fin.ignore(1);
				getline(fin, name);
				if (tmp != NULL) delete tmp;
				tmp = new FileSave(level, name);
				this->File.push_back(tmp);
				GotoXY(W+2, line);
				cout << numberOfSave + 1 << ". " << File[numberOfSave]->getName() << " (Level: " << File[numberOfSave]->getLevel() << ")";
				numberOfSave++;
				line++;
			}
			char type = _getch();
			if (type != 27) {
				int a = type - '0';
				if (a > 0 && a <= numberOfSave) {
					this->presentLevel = File[a-1]->getLevel() - 1;
					UpdateLevel();
				}
			}
		}
		fin.close();
	}
	Clean();
}

void CGAME::saveGame(){
	Clean();
	ofstream fout;
	string name = "";
	char a = 'a';
	int W = WIDTH + 6;
	int H = HEIGHT - 5;
	int cnt = 0;
	gotoXY(W, H); cout << "Input the name of your file" << endl;
	gotoXY(W, H + 1); cout << "(maximum 15 characters) : " << endl;
	while (a != 27) {
		gotoXY(W + 2, H + 2); cout << name << "                    ";
		a = _getch();
		if (a == 8 && name.size() > 0) {
			name.pop_back();
			cnt--;
		}
		else if (a == 13) {
			fout.open("SaveFile.txt");
			if (!fout.is_open()) {
				GotoXY(W + 2, H + 4); cout << "Can not open file!";
				Sleep(500);
				return;
			}

			fout << name << endl;
			fout << presentLevel << endl;
			fout.close();
			GotoXY(W + 2, H + 4); cout << "Save successfully!";
			Sleep(2000);
			break;

		}
		else if (name.size() >= 15) {
			gotoXY(W , H + 4); cout << "Your string are too long";
			Sleep(500);
			name = "";
			cnt = 0;
			Clean();
            gotoXY(W, H); cout << "Input the name of your file" << endl;
            gotoXY(W, H + 1); cout << "(maximum 15 characters) : " << endl;
		}
		else {
			name += a;
			if (a != 8) cnt++;
		}
	}
	Clean();
}
void CGAME::pauseGame(HANDLE){
    //Pause thread;
}

void CGAME::resumeGame(HANDLE){
    //return to thread;
}

bool CGAME::isCrashed(){
    return (cn.isImpact() || cn.isImpact() || cn.isImpact() || cn.isImpact());
}
void CGAME::updatePosPeople(char tmp){
    int d = lv[curLevel-1]->getDistance();
    switch(tmp){
    case 87:{
        if(cn->getY()!= Finish)
            cn->Up(d);
        break;
    };
    case 83:{
        if(cn->getY()!= HEIGHT-3)
            cn->Down(d);
        break;
    };
    case 65:{
        if(cn->getX() >= TOPLEFT + 4)
            cn->Left(4);
        break;
    };
    case 68:{
        if(cn->getX() >= TOPRIGHT - 4)
            cn->Right(4);
        break;
    };
    default:
        break;
    }
    if(cn->isFinish(Finish)){
        updateLevel();
    }
}

void GGAME::clean(){
    int i = HEIGHT - 5;
	while (i < HEIGHT) {
		GotoXY(WIDTH + 1, i); for (int j = 0; j < WIDTH + 20; j++) cout << " ";
		i += 1;
	}
}
void CGAME::updatePosVehicle()
void CGAME::updatePosAnimal()

Level::Level(int lane, int distance, int speed, int car, int struck, int bird, int dinasour) {
	this->lane = lane; this->speed = speed; this->car = car; this->truck = struck;
	this->bird = bird; this->dina = dinasour; this->distance = distance;
}

int Level::getLane() { return lane; }
int Level::getDistance() { return distance; }
int Level::getSpeed() { return speed; }
int Level::AmounrOfBird() { return bird; }
int Level::AmountOfCar() { return car; }
int Level::AmountOfDinasour() { return dina; }
int Level::AmountOfTruck() { return truck; }
