#include"MultiThread.h"

void RunGame() {
	bool alive = true;
	int time = 1;
	char move = ' ';
	bool Is_move = true;
	CGAME* pp;
	while (alive) {
		time++;
		if (Is_move == false) {
			continue;
		}
		if (!pp->getPeople()->isDead()) 
			pp->updatePosPeople(move, time);

		if (pp->IsFinish()) {
			pp->ScoreBoard(true);
			alive = false;
			break;
		}


		move = ' ';

		if (time % 300 > 1 - 1) {
			pp->TrafficLight(1);
			//pp->Update();
		}
		else {

			pp->TrafficLight(2);
		}

		if (pp->isCrashed()) {
			cout << "\a";
			pp->ScoreBoard(false);
			alive = false;
			break;

		}

		Sleep(100 / pp->getSpeed());
	}
}