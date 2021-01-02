//#ifndef CGAME_H_INCLUDED
//#define CGAME_H_INCLUDED
#include "Console.h"
#include "Files.h"
#include "Traffic_Light.h"
#include <stdio.h>
#include <vector>
using namespace std;

int WIDTH = 80;
int HEIGHT = 29;
int LEFTMOST = 3;
int RIGHTMOST = WIDTH - 6;

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
	int AmounrOfBird();
};


class CGAME{
private:
    CTRUCK* axt;
    CCAR* axh;
    CDINASOUR* akl;
    CBIRD* ac;
    int Finish //pos y-axis represent the end point of a level;
    CPEOPLE cn;
    LEVEL *lv;
    int curLevel = 0;
    vector<FileSave*>File;

public:
    CGAME() {}; //Chuẩn bị dữ liệu cho tất cả các đối tượng
    void drawGame(); //Thực hiện vẽ trò chơi ra màn hình sau khi có dữ liệu
    ~CGAME() {}; // Hủy tài nguyên đã cấp phát
    CPEOPLE getPeople();//Lấy thông tin người
    vector <CVEHICLE*> getVehicle();//Lấy danh sách các xe
    vector <CANIMAL> getAnimal(); //Lấy danh sách các thú
    void resetGame(); // Thực hiện thiết lập lại toàn bộ dữ liệu như lúc đầu
    void exitGame(HANDLE); // Thực hiện thoát Thread
    void startGame(); // Thực hiện bắt đầu vào trò chơi
    void loadGame(); // Thực hiện tải lại trò chơi đã lưu
    void saveGame(); // Thực hiện lưu lại dữ liệu trò chơi
    void pauseGame(HANDLE); // Tạm dừng Thread
    void resumeGame(HANDLE); //Quay lai Thread
    void updatePosPeople(char tmp); //Thực hiện điều khiển di chuyển của CPEOPLE
    void updatePosVehicle(); //Thực hiện cho CTRUCK & CCAR di chuyển
    void updatePosAnimal();//Thực hiện cho CDINAUSOR & CBIRD di chuyển
    bool isCrashed();
    void updateLevel();
    int getCurLevel() {
        return curLevel;
    }
    void Clean();
};

#endif // CGAME_H_INCLUDED
