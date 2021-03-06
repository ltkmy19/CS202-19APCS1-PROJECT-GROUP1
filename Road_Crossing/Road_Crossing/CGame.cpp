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
	lv[8] = new Level(9, 3, 3, 5, 5, 4, 4);
	lv[9] = new Level(9, 3, 4, 5, 5, 5, 5);
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

string CGAME::getFileLocation() {
	clean();
	string name = "";
	char a = 'a';
	int W = Width + 6;
	int H = Height - 7;
	int cnt = 0;
	int line = H + 2;
	LightCyan();
	gotoXY (0, Height); cout << "Input the file path: " << endl;
	LightGray();
	while (a != 27) {
		gotoXY(21, Height); cout << name << "                    ";
		a = _getch();
		if (a == 8 && name.size() > 0) {
			name.pop_back();
			cnt--;
		}
		else if (a == 13) {
			clean();
			gotoXY(0, Height);
			for (int i = 0; i < 120; i++) {
				cout << " ";
			}
			gotoXY(0, Height+1);
			for (int i = 0; i < 120; i++) {
				cout << " ";
			}
			return name;
		}
		
		else {
			name += a;
			if (a != 8) cnt++;
		}
	}
}
void CGAME::loadGame() {
	clean();
	ifstream fin;
	int numberOfSave = 0;
	int W = Width + 6;
	int H = Height - 5;
	int level = 0, line = H-2;
	string name = "",file = "";
	char peopleType = 1;
	fin.open(getFileLocation());
	if (!fin.is_open()) {
		gotoXY(W + 2, H + 2); cout << "Can not open file!";
		Sleep(2000);
		clean();
		return;
	}
	else {
		Yellow();
		gotoXY(W + 2, line - 1); cout << "LIST OF SAVED FILES";
		LightGray();
		if (fin.eof()) cout << "There is no save file!" << endl;
		else {
			while (!(fin.peek() == ifstream::traits_type::eof())) {
			//	fin.ignore(100, '\n');
				fin.get(peopleType);
				fin.ignore(100, '\n');

				getline(fin, name);
				fin >> level;
				fin.ignore(100, '\n');
				if (File[numberOfSave] != NULL) {
					delete File[numberOfSave];
					File[numberOfSave] = NULL;
				}
				File[numberOfSave] = new FileSave(level, name, peopleType);
				gotoXY(W+2, line);
				cout << numberOfSave + 1 << ". " << File[numberOfSave]->getName() << " (Level: " << File[numberOfSave]->getLevel() << ")";
				++numberOfSave;
				++line;
			}
			char type = _getch();
			if (type != 27) {
				int a = type - '0';
				if (a > 0 && a <= numberOfSave) {
					this->curLevel = File[a-1]->getLevel() - 1;
					this->peopleType = File[a - 1]->getCharacter();
					if (curLevel == 0) {
						curLevel++;
						drawGame();
					}
					else {
						UpdateLevel();
					}
				}
				else {
					clean();
					gotoXY(W + 1, H + 2); cout << "Invalid choice!!!!!";
					Sleep(2000);
					clean();
					return;
				}
			}
			clean();
		}
		fin.close();
	}
	gotoXY(W + 2, H + 2); cout << "Press P to resume saved game";
	Sleep(2000);
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
	string tmp = getFileLocation();
	LightCyan();
	gotoXY(W, H); cout << "Input the name of your file" << endl;
	gotoXY(W, H + 1); cout << "(maximum 15 characters) : " << endl;
	LightGray();
	while (a != 27) {
		gotoXY(W + 2, H + 2); cout << name << "                    ";
		a = _getch();
		if (a == 8 && name.size() > 0) {
			name.pop_back();
			cnt--;
		}
		else if (a == 13) {
			fout.open(tmp,fstream::app);
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
	if (pp->ISCrashedBird(ac, lv[curLevel - 1]->AmountOfBird())|| pp->ISCrashedDinausor(akl, lv[curLevel - 1]->AmountOfDinasour())|| pp->ISCrashedCar(axh, lv[curLevel - 1]->AmountOfCar())||pp->ISCrashedTruck(axt, lv[curLevel - 1]->AmountOfTruck())) {
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
		CreatorVehicle* createCar = NULL;
        if(axh[i] == NULL || axh[i]->IsDone()){
            if(axh[i] != NULL) delete axh[i];
            a = 1 + rand() % (level->getLane()-2);
            b = 10;
			if (a % 2 == 0) {
				createCar = new CreatorCar(Endlane, Finish + a * level->getDistance() - 1);
				axh[i] = createCar->factoryMethod();
			}
			else {
				createCar = new CreatorCar(Startlane, Finish + a * level->getDistance() - 1);
				axh[i] = createCar->factoryMethod();
			}
        }
        else axh[i]->Move(10,10);
    }
    for(int i = 0;i < level->AmountOfTruck();i++){
		CreatorVehicle* createTruck = NULL;
        if(axt[i] == NULL || axt[i]->IsDone()){
            if(axt[i] != NULL) delete axt[i];
            a = 1 + rand() % (level->getLane()-2);
            b = 10;
			if (a % 2 == 0) {
				createTruck = new CreatorTruck(Endlane, Finish + a * level->getDistance() - 1);
				axt[i] = createTruck->factoryMethod();
			}
			else {
				createTruck = new CreatorTruck(Startlane, Finish + a * level->getDistance() - 1);
				axt[i] = createTruck->factoryMethod();
			}
        }
        else axt[i]->Move(10,10);
    }

}
void CGAME::updatePosAnimal() {
    Level* level = lv[curLevel-1];
    int a,b;
    for(int i = 0;i < level->AmountOfBird();i++){
		CreatorAnimal* createBird = NULL;
        if(ac[i] == NULL || ac[i]->IsDone()){
            if(ac[i] != NULL) delete ac[i];
            a = 1 + rand() % (level->getLane()-2);
            b = 10;
			if (a % 2 == 0) {
				createBird = new CreatorBird(Endlane, Finish + a * level->getDistance() - 1);
				ac[i] = createBird->factoryMethod();
			}
			else {
				createBird = new CreatorBird(Startlane, Finish + a * level->getDistance() - 1);
				ac[i] = createBird->factoryMethod();
			}
        }
        else ac[i]->Move(10,10);
    }
    for(int i = 0;i < level->AmountOfDinasour();i++){
		CreatorAnimal* createDina = NULL;
        if(akl[i] == NULL || akl[i]->IsDone()){
            if(akl[i] != NULL) delete akl[i];
            a = 1 + rand() % (level->getLane()-2);
			if (a % 2 == 0) {
				createDina = new CreatorDinausor(Endlane, Finish + a * level->getDistance() - 1);
				akl[i] = createDina->factoryMethod();
			}
			else {
				createDina = new CreatorDinausor(Startlane, Finish + a * level->getDistance() - 1);
				akl[i] = createDina->factoryMethod();
			}
        }
        else akl[i]->Move(10,10);
    }
}

bool CGAME::isFinish(){
    return (curLevel > Max_level) ? true : false;
}
void CGAME::UpdateLevel() {
	deleteGame();
	curLevel++;
    if(!isFinish()) drawGame();
}

void CGAME::EndGame(bool Win) {
	mciSendString("stop  ingame.wav", NULL, 0, NULL);
	system("cls");
	if (Win) {
		mciSendString("play  win.wav", NULL, 0, NULL);
		Red();
		ifstream Reader("Win.txt");
		string Art = getFileContents(Reader);
		cout << Art << endl;	
		White();
	}
	else {
		Red();
		gotoXY(Width / 2, Height / 2);
		cout << "You are stuck at level " << curLevel << ". BETTER LUCK NEXT TIME! "<<endl;
		White();
	}
}
void CGAME::loadLevel(int level) {
	curLevel = level;
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
