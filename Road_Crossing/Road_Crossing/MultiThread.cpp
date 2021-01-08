#include"MultiThread.h"

void RunGame(CGAME*& pp, bool& Is_move, int& times, bool& alive, char& MOVE) {
	while (alive) {
		if(Is_move)
			times++;
		if (!Is_move) {
			continue;
		}
		if (!pp->getPeople()->isDead()) {
			pp->updatePosPeople(MOVE,times);
		}
		if (pp->isFinish()) {
			system("cls");
			mciSendString("stop  ingame.wav", NULL, 0, NULL);
			mciSendString("play  win.wav", NULL, 0, NULL);
			Red();
			ifstream Reader("Win.txt");
			string Art = getFileContents(Reader);
			cout << Art << endl;
			Sleep(4000);
			White();
			exit(0);
		/*	pp->EndGame(true);
			alive = false;*/
			break;
		}

		MOVE = ' ';
		if ( times % 150 > Stoptime-20) {
			pp->TrafficLight(false);
			pp->updatePosAnimal();
			pp->updatePosVehicle();
		}
		else {
			pp->TrafficLight(true);
		}

		if (pp->isCrashed()) {
			pp->EndGame(false);
			alive = false;
			break;

		}

		Sleep(100 / pp->getSpeed());
	}
}
