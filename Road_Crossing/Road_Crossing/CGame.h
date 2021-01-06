#ifndef CGAME_H_INCLUDED
#define CGAME_H_INCLUDED
#include "Files.h"
#include "Traffic_Light.h"
#include "CPeople.h"
#include <stdio.h>
#include <vector>
#include <fstream>

using namespace std;

const int Max_level = 10;
const float Height = 29;
const float Width = 80;
const int Startlane = 3;
const int Endlane = Width - 6;
const int Intwidth = 118 - Width;
const int Stoptime = 41;
int LEFTMOST = 3;
int RIGHTMOST = Width - 6;

class FileSave{
private:
    int level;
    string name;
public:
    FileSave() {};
    FileSave(int lv,string name){
        this->level = lv;
        this->name = name;
    }
    ~FileSave() {};
    int getLevel(){
        return level;
    }
    string getName(){
        return name;
    }
};

class Level {
private:
	int lane; // number of lanes
	int distance;
	int speed; // speed of obstacle
	int car, truck, dina, bird;
public:
	Level(int, int, int, int, int, int, int);
	int getLane();
	int getDistance();
	int getSpeed();
	int AmountOfCar();
	int AmountOfTruck();
	int AmountOfDinasour();
	int AmountOfBird();
};


class CGAME{
private:

	vector<CTRUCK*>axt;
	vector<CCAR*>axh;
	vector<CDINAUSOR*>akl;
	vector<CBIRD*>ac;
	vector<Level*>lv;
	int Finish; //pos y-axis represent the end point of a level;
    CPEOPLE* pp;
    int curLevel = 0;
    vector<FileSave*>File;

public:

    CGAME() ;
    void drawGame();
	CPEOPLE* getPeople() {
		return pp;
	};
    vector <CVEHICLE*> getVehicle();
    vector <CANIMAL*> getAnimal();
    void resetGame();
    void exitGame(HANDLE);
    void startGame();
    void loadGame();
    void saveGame(); //
    void pauseGame(HANDLE);
    void resumeGame(HANDLE);
    void updatePosPeople(char tmp);
    void updatePosVehicle();
    void updatePosAnimal();
    bool isFinish();
    bool isCrashed();
    void UpdateLevel();
    int getCurLevel() {
        return curLevel;
    }
    void clean();
    void TrafficLight(bool RedLight);
    void EndGame(bool Win);
    void deleteGame();
};


#endif // CGAME_H_INCLUDED
