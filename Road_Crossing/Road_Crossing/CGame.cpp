//#include "CGame.h"
//using namespace std;
//
//CGame::CGAME(){
//
//}
//
//void CGAME::drawGame() {
//    Magenta();
//    gotoXY(0, 0); cout << (char)218; for (int i = 1; i < WIDTH ;i++) { cout << (char)196; } cout << (char)191;
//    gotoXY(0, 1); for (int i = 2; i < HEIGHT; i++) { cout << (char)179; gotoXY(0, i); }
//    gotoXY(0, HEIGHT - 1); cout << (char)192; for (int i = 1; i < WIDTH; i++) { cout << (char)196; }
//    gotoXY(WIDTH, 1); for (int i = 2; i < HEIGHT; i++) { cout << (char)179; gotoXY(WIDTH, i); } cout << (char)217;
//}

//CGAME::~CGAME(){
//    delete[] axh;
//    delete[] axt;
//    delete[] akl;
//    delete[] ac;
//    delete[] lv;
//}
//
//CPEOPLE CGAME::getPeople(){
//    return cn;
//}
//
//vector <CVEHICLE*> CGAME::getVehicle(){
//    int c = /*max car at this level*/;
//    int t = /*max truck at this level*/;
//    vector<CVEHICLE*>tmp;
//    for(int i = 0;i < c;i++){
//        tmp.push_back(&(axh[i]));
//    }
//    for(int j = 0;j < t;j++){
//        tmp.push_back(&(axt[j]));
//    }
//    return tmp;
//}
//
//vector <CANIMAL*> CGAME::getAnimal(){
//    int d = /*max dinasour at this level*/;
//    int b = /*max bird at this level*/;
//    vector<CANIMAL*>tmp;
//    for(int i = 0;i < d;i++){
//        tmp.push_back(&(akl[i]));
//    }
//    for(int j = 0;j < b;j++){
//        tmp.push_back(&(ac[j]));
//    }
//    return tmp;
//}

//void CGAME::resetGame()
//void CGAME::exitGame(HANDLE)
//void CGAME::startGame()
//void CGAME::loadGame(istream)
//void CGAME::saveGame(istream)
//void CGAME::pauseGame(HANDLE)
//void CGAME::resumeGame(HANDLE)
//void CGAME::updatePosPeople(char)
//void CGAME::updatePosVehicle()
//void CGAME::updatePosAnimal()
