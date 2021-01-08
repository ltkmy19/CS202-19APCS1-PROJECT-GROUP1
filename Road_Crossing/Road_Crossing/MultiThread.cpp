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
			pp->EndGame(true);
			alive = false;
			break;
		}

		MOVE = ' ';
		if (times % 300 > Stoptime-1) {
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