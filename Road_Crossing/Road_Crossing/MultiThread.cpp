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
			mciSendString("play  win.wav", NULL, 0, NULL);
			Red();
			ifstream Reader("Win.txt");
			string Art = getFileContents(Reader);
			cout << Art << endl;
			Sleep(4000);
			White();
			delete pp;
			exit(0);
		/*	pp->EndGame(true);
			alive = false;*/
			break;
		}

		MOVE = ' ';
		if ( times % 130 > Stoptime-10) {
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

		Sleep(130 / pp->getSpeed());
	}
}
