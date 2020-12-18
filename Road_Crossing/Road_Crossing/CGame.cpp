//#include "CGame.h"
//#include <fstream>
//using namespace std;
//
//CGame::CGAME(){
//
//}
//
//void CGAME::drawGame() {
//    LightMagenta();
//    gotoXY(0, 0); cout << (char)218; for (int i = 1; i < WIDTH; i++) { cout << (char)196; } cout << (char)191;
//    gotoXY(0, 1); for (int i = 2; i < HEIGHT; i++) { cout << (char)179; gotoXY(0, i); }
//    gotoXY(0, HEIGHT - 1); cout << (char)192; for (int i = 1; i < WIDTH; i++) { cout << (char)196; }
//    gotoXY(WIDTH, 1); for (int i = 2; i < HEIGHT; i++) { cout << (char)179; gotoXY(WIDTH, i); } cout << (char)217;
//
//    int W = WIDTH + 8;
//    int H = HEIGHT - 10;
//    gotoXY(W, 2); cout << (char)218; for (int i = W+1; i < W+30;i++) { cout << (char)196; } cout << (char)191;
//    gotoXY(W, 3); for (int i = 4; i < H; i++) { cout << (char)179; gotoXY(W, i); }
//    gotoXY(W, H-1); cout << (char)192; for (int i = W+1; i < W+30; i++) { cout << (char)196; }
//    gotoXY(W+30, 3); for (int i = 3; i < H; i++) { cout << (char)179; gotoXY(W+30, i); } cout << (char)217;
//
//    LightCyan();
//    gotoXY(W + 1, 4); cout << "WELCOME TO CROSSING ROAD! ^_^";
//    gotoXY(W + 7, 6); cout << "press ESC to exit ";
//    gotoXY(W + 5, 8); cout << "Level: 1";
//    gotoXY(W + 5, 10); cout << "P: Pause/Resume ";
//    gotoXY(W + 6, 12); cout << "Please pause before: ";
//    gotoXY(W + 5, 14); cout << "K: Load game ";
//    gotoXY(W + 5, 16); cout << "S: Save game ";
//}
//
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
//
//void CGAME::resetGame()
//void CGAME::exitGame(HANDLE)
//void CGAME::startGame()
//
//
//void CGAME::loadGame(){
//    ifstream fin;
//    int numberOfSave = 0;
//    int level= 0, line = 0;
//    string name = "";
//    FileSave *tmp = nullptr;
//    fin.open("SaveFiles.txt");
//    if(!fin.is_open()) cout << "Can not open file!" << endl;
//    else{
//        if(fin.eof()) cout << "There is no save file!"<<endl;
//        else{
//            while(!fin.eof()){
//                fin >> level;
//                getline(fin,name);
//                tmp = new FileSave(level, name);
//                this->File.push_back(tmp);
//                gotoXY(WIDTH+8,line);
//                cout << numberOfSave+1 <<". "<< File[numberOfSave]->getName() <<" (Level: "<<File[numberOfSave]->getLevel()<<")";
//                numberOfSave++;
//                line++;
//
//            }
//            char type = _getch();
//            if(type != 27){
//                int a = type - '0';
//                if(a > 0 && a <= numberOfSave){
//                    this->curLevel = File[a]->getLevel()-1;
//                    updateLevel();
//                }
//            }
//        }
//        fin.close();
//    }
//}
//
//void CGAME::saveGame(){
//	Clean();
//	ofstream fout;
//	string name = "";
//	char a = 'a';
//	int W = WIDTH + 6;
//	int H = HEIGHT - 5;
//	int cnt = 0;
//	gotoXY(W, H); cout << "Input the name of your file" << endl;
//	gotoXY(W, H + 1); cout << "(maximum 15 characters) : " << endl;
//	while (a != 27) {
//		gotoXY(W + 2, H + 2); cout << name << "                    ";
//		a = _getch();
//		if (a == 8 && name.size() > 0) {
//			name.pop_back();
//			cnt--;
//		}
//		else if (a == 13) {
//			fout.open("SaveFile.txt");
//			if (!fout.is_open()) {
//				GotoXY(W + 2, H + 4); cout << "Can not open file!";
//				Sleep(500);
//				return;
//			}
//
//			fout << name << endl;
//			fout << presentLevel << endl;
//			fout.close();
//			GotoXY(W + 2, H + 4); cout << "Save successfully!";
//			Sleep(2000);
//			break;
//
//		}
//		else if (name.size() >= 15) {
//			gotoXY(W , H + 4); cout << "Your string are too long";
//			Sleep(500);
//			name = "";
//			cnt = 0;
//			Clean();
//            gotoXY(W, H); cout << "Input the name of your file" << endl;
//            gotoXY(W, H + 1); cout << "(maximum 15 characters) : " << endl;
//		}
//		else {
//			name += a;
//			if (a != 8) cnt++;
//		}
//	}
//	Clean();
//}
//void CGAME::pauseGame(HANDLE)
//void CGAME::resumeGame(HANDLE)
//void CGAME::updatePosPeople(char)
//void CGAME::updatePosVehicle()
//void CGAME::updatePosAnimal()
