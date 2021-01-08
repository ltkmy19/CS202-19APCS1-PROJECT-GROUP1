#include "CGame.h"

using namespace std;

CGAME::CGAME(char ppType){
    peopleType = ppType;
	lv[0] = new Level(4, 7, 3, 0, 0, 0, 5);//int lanes, int distances, int speeds, int cars, int trucks, int birds, int dinasours
	lv[1] = new Level(4, 7, 2, 2, 2, 2, 1);
	lv[2] = new Level(5, 6, 2, 2, 3, 3, 3);
	lv[3] = new Level(5, 6, 2, 3, 3, 2, 3);
	lv[4] = new Level(5, 6, 3, 3, 3, 3, 2);
	lv[5] = new Level(7, 4, 2, 3, 3, 3, 3);
	lv[6] = new Level(7, 4, 3, 3, 3, 3, 3);
	lv[7] = new Level(7, 4, 4, 4, 4, 4, 4);
	lv[8] = new Level(9, 3, 3, 6, 5, 4, 4);
	lv[9] = new Level(9, 3, 4, 7, 7, 7, 7);
	curLevel = 1;

}


void CGAME::drawGame() {
	system("cls");
    LightMagenta();
    gotoXY(0, 0); cout << (char)218; for (int i = 1; i < Width; i++) { cout << (char)196; } cout << (char)191;
    gotoXY(0, 1); for (int i = 2; i < Height; i++) { cout << (char)179; gotoXY(0, i); }
    gotoXY(0, Height - 1); cout << (char)192; for (int i = 1; i < Width; i++) { cout << (char)196; }
    gotoXY(Width, 1); for (int i = 2; i < Height; i++) { cout << (char)179; gotoXY(Width, i); } cout << (char)217;

    int W = Width + 8;
    int H = Height - 10;
    gotoXY(W, 2); cout << (char)218; for (int i = W+1; i < W+30;i++) { cout << (char)196; } cout << (char)191;
    gotoXY(W, 3); for (int i = 4; i < H; i++) { cout << (char)179; gotoXY(W, i); }
    gotoXY(W, H-1); cout << (char)192; for (int i = W+1; i < W+30; i++) { cout << (char)196; }
    gotoXY(W+30, 3); for (int i = 3; i < H; i++) { cout << (char)179; gotoXY(W+30, i); } cout << (char)217;

    LightCyan();
    gotoXY(W + 1, 4); cout << "WELCOME TO CROSSING ROAD! ^_^";
    gotoXY(W + 7, 6); cout << "press ESC to exit ";
    gotoXY(W + 5, 8); cout << "Level: " << curLevel;
    gotoXY(W + 5, 10); cout << "P: Pause/Resume ";
    gotoXY(W + 6, 12); cout << "Please pause before: ";
    gotoXY(W + 5, 14); cout << "T: Load game ";
    gotoXY(W + 5, 16); cout << "L: Save game ";

	int d = lv[curLevel - 1]->getDistance();
	int n = lv[curLevel - 1]->getLane();
	int m = Height;

	for (int i = 0; i < n; i++) {
		gotoXY(Startlane, m - 2); Finish = m - 2; m -= d;
		for (int j = 0; j < Endlane; ++j) cout << "_";
	}
    this->pp = new CPEOPLE(Width/2,Height-3,peopleType);
    TrafficLight(false);
}




vector <CVEHICLE*> CGAME::getVehicle(){
    int c = lv[curLevel-1]->AmountOfCar();
    int t = lv[curLevel-1]->AmountOfTruck();;
    vector<CVEHICLE*>tmp;
    for(int i = 0;i < c;i++){
        tmp.push_back(axh[i]);
    }
    for(int j = 0;j < t;j++){
        tmp.push_back(axt[j]);
    }
    return tmp;
}

vector <CANIMAL*> CGAME::getAnimal(){
    int d = lv[curLevel-1]->AmountOfDinasour();
    int b = lv[curLevel-1]->AmountOfBird();
    vector<CANIMAL*>tmp;
    for(int i = 0;i < d;i++){
        tmp.push_back(akl[i]);
    }
    for(int j = 0;j < b;j++){
        tmp.push_back(ac[j]);
    }
    return tmp;
}

void CGAME::deleteGame() {
	for (int i = 0; i < lv[curLevel - 1]->AmountOfCar(); i++) {
		delete axh[i];
		axh[i] = NULL;
	}
	for (int i = 0; i < lv[curLevel - 1]->AmountOfTruck(); i++) {
		delete axt[i];
		axt[i] = NULL;
	}
	for (int i = 0; i < lv[curLevel - 1]->AmountOfBird(); i++){
		delete ac[i];
		ac[i] = NULL;
	}
	for (int i = 0; i < lv[curLevel - 1]->AmountOfDinasour(); i++) {
		delete akl[i];
		akl[i] = NULL;
	}
    delete pp;
}

void CGAME::resetGame() {
    deleteGame();
    curLevel = 1;
    drawGame();
}
void CGAME::exitGame(HANDLE) {

}
void CGAME::startGame() {
    drawGame();
}


void CGAME::loadGame() {
	clean();
	ifstream fin;
	int numberOfSave = 0;
	int W = Width + 6;
	int H = Height - 5;
	int level = 0, line = H;
	string name = "";
	FileSave* tmp = nullptr;
	fin.open("SaveFiles.txt");
	if (!fin.is_open()) {
		gotoXY(W + 2, H + 4); cout << "Can not open file!";
		Sleep(500);
		clean();
		return;
	}
	else {
		if (fin.eof()) cout << "There is no save file!" << endl;
		else {
			while (!fin.eof()) {
				fin >> level;
				fin.ignore(1);
				getline(fin, name);
				fin.get(peopleType);
				if (tmp != NULL) delete tmp;
				tmp = new FileSave(level, name);
				File[numberOfSave] = (tmp);
				gotoXY(W+2, line);
				cout << numberOfSave + 1 << ". " << File[numberOfSave]->getName() << " (Level: " << File[numberOfSave]->getLevel() << ")";
				numberOfSave++;
				line++;
			}
			char type = _getch();
			if (type != 27) {
				int a = type - '0';
				if (a > 0 && a <= numberOfSave) {
					this->curLevel = File[a-1]->getLevel() - 1;
					UpdateLevel();
				}
			}
		}
		fin.close();
	}
	clean();
}

void CGAME::saveGame(){
	clean();
	ofstream fout;
	string name = "";
	char a = 'a';
	int W = Width + 6;
	int H = Height - 5;
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
			fout.open("SaveFile.txt",fstream::app);
			if (!fout.is_open()) {
				gotoXY(W + 2, H + 4); cout << "Can not open file!";
				Sleep(500);
				return;
			}
            fout << peopleType << endl;
			fout << name << endl;
			fout << curLevel << endl;
			fout.close();
			gotoXY(W + 2, H + 4); cout << "Save successfully!";
			Sleep(2000);
			break;

		}
		else if (name.size() >= 15) {
			gotoXY(W , H + 4); cout << "Your string are too long";
			Sleep(500);
			name = "";
			cnt = 0;
			clean();
            gotoXY(W, H); cout << "Input the name of your file" << endl;
            gotoXY(W, H + 1); cout << "(maximum 15 characters) : " << endl;
		}
		else {
			name += a;
			if (a != 8) cnt++;
		}
	}
	clean();
}
void CGAME::pauseGame(HANDLE){
    //Pause thread;
}

void CGAME::resumeGame(HANDLE){
    //return to thread;
}

bool CGAME::isCrashed(){
	if (pp->ISCrashed(ac, lv[curLevel - 1]->AmountOfBird())|| pp->ISCrashed(akl, lv[curLevel - 1]->AmountOfDinasour())|| pp->ISCrashed(axh, lv[curLevel - 1]->AmountOfCar())||pp->ISCrashed(axt, lv[curLevel - 1]->AmountOfTruck())) {
		return true;
	}
	return false;
}
void CGAME::updatePosPeople(char tmp,int& times){
    int d = lv[curLevel-1]->getDistance();
    switch(tmp) {
	case  87:
    case 119:{
        if(pp->getY()!= Finish)
            pp->Up(d);
        break;
    };
	case 83:
    case 115:{
        if(pp->getY()!= Height-3)
            pp->Down(d);
        break;
    };
	case 65:
    case 97:{
        if(pp->getX() >= LEFTMOST + 4)
            pp->Left(4);
        break;
    };
	case 68:
    case 100:{
        if(pp->getX() <= RIGHTMOST - 4)
            pp->Right(4);
        break;
    };
    default:
        break;
    }
    if(pp->isFinish(Finish)){
        UpdateLevel();
		times = Stoptime;
    }
}

void CGAME::clean(){
    int i = Height - 5;
	while (i < Height) {
		gotoXY(Width + 1, i); for (int j = 0; j < Intwidth - 1 ; j++) cout << " ";
		i += 1;
	}
}

void CGAME::updatePosVehicle() {
    Level* level = lv[curLevel-1];
    int a,b;
    for(int i = 0;i < level->AmountOfCar();i++){
        if(axh[i] == NULL || axh[i]->IsDone()){
            if(axh[i] != NULL) delete axh[i];
            a = 1 + rand() % (level->getLane()-2);
            b = 10;
            if(a % 2) axh[i] = new CCAR(Endlane,Finish + a*level->getDistance()-1);
            else axh[i] = new CCAR(Startlane,Finish + a*level->getDistance()-1);
        }
        else axh[i]->Move(10,10);
    }
    for(int i = 0;i < level->AmountOfTruck();i++){
        if(axt[i] == NULL || axt[i]->IsDone()){
            if(axt[i] != NULL) delete axt[i];
            a = 1 + rand() % (level->getLane()-2);
            b = 10;
            if(a % 2) axt[i] = new CTRUCK(Endlane,Finish + a*level->getDistance()-1);
            else axt[i] = new CTRUCK(Startlane,Finish + a*level->getDistance()-1);
        }
        else axt[i]->Move(10,10);
    }

}
void CGAME::updatePosAnimal() {
    Level* level = lv[curLevel-1];
    int a,b;
    for(int i = 0;i < level->AmountOfBird();i++){
        if(ac[i] == NULL || ac[i]->IsDone()){
            if(ac[i] != NULL) delete ac[i];
            a = 1 + rand() % (level->getLane()-2);
            b = 10;
            if(a % 2 == 0)
				ac[i] = new CBIRD(Endlane,Finish + a*level->getDistance()-1);
            else
				ac[i] = new CBIRD(Startlane,Finish + a*level->getDistance()-1);
        }
        else ac[i]->Move(10,10);
    }
    for(int i = 0;i < level->AmountOfDinasour();i++){
        if(akl[i] == NULL || akl[i]->IsDone()){
            if(akl[i] != NULL) delete akl[i];
            a = 1 + rand() % (level->getLane()-2);
            b = rand()%7*12;
            if(a % 2 == 0) \
				akl[i] = new CDINAUSOR(Endlane,Finish + a*level->getDistance()-1);
            else
				akl[i] = new CDINAUSOR(Startlane,Finish + a*level->getDistance()-1);
        }
        else akl[i]->Move(10,10);
    }
}

bool CGAME::isFinish(){
    return (curLevel > Max_level) ? true : false;
}
void CGAME::UpdateLevel() {
    deleteGame();
    ++curLevel;
    if(!isFinish()) drawGame();
}

void CGAME::EndGame(bool Win) {
	mciSendString("stop  ingame.wav", NULL, 0, NULL);
	system("cls");
	if (Win) {
		Red();
		ifstream Reader("Win.txt");
		string Art = getFileContents(Reader);
		cout << Art << endl;
		White();
	}
	else {
		gotoXY(Width / 2, Height / 2);

		cout << "You stuck at level " << curLevel << ".BETTER LUCK NEXT TIME! "<<endl;
	}
}

void CGAME::TrafficLight(bool RedLight){
    Lights tmp;
    int d = lv[curLevel - 1]->getDistance();
	int n = lv[curLevel - 1]->getLane();
	int m = Height-d-2;
	for(int i = 0;i < n-2; i++){
        int p;
        if(i % 2 == 0) p = Startlane-1;
        else p = Endlane + 3;
        if(RedLight) tmp.RedLight(p,m);
        else tmp.GreenLight(p,m);
        m -= d;
	}
}

Level::Level(int lanes, int distances, int speeds, int cars, int trucks, int birds, int dinasours) {
	lane = lanes;
	speed = speeds;
	car = cars;
	truck = trucks;
	bird = birds;
	dina = dinasours;
	distance = distances;
}


int Level::getLane() { return lane; }
int Level::getDistance() { return distance; }
int Level::getSpeed() { return speed; }
int Level::AmountOfBird() { return bird; }
int Level::AmountOfCar() { return car; }
int Level::AmountOfDinasour() { return dina; }
int Level::AmountOfTruck() { return truck; }
