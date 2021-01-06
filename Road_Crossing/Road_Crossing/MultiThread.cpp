#include"MultiThread.h"

void RunGame(CGAME*& pp, bool& Is_move, int& ti, bool& alive, char& MOVE) {
	while (alive) {
		++ti;
		if (!Is_move) {
			continue;
		}
		if (!pp->getPeople()->isDead()) {
			pp->updatePosPeople(MOVE);
		}
		if (pp->isFinish()) {
			pp->EndGame(true);
			alive = false;
			break;
		}

		MOVE = ' ';
		if (ti % 300 > Stoptime-1) {
			pp->TrafficLight(true);
			//pp->Update();
		}
		else {
			pp->TrafficLight(false);
			pp->updatePosAnimal();
		}

		if (pp->isCrashed()) {
			pp->EndGame(false);
			alive = false;
			break;

		}

	//	Sleep(100 / pp->getSpeed());
	}
}