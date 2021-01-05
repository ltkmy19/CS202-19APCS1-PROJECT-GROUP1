#include"MultiThread.h"
bool alive = true;
int time = 1;
char move = ' ';
bool Is_move = true;
void SubThread() {
	while (alive) {
		++time;
		if (!Is_move) continue;
		if (!pp->getPeople()->isDead()) 
			pp->updatePosPeople(move, time);

		if (pp->IsFinish()) {
			pp->ScoreBoard(true);
			alive = false;
			break;
		}


		move = ' ';

		if (time % 300 > 1 - 1) {
			pp->RedLight();
			pp->Update();
		}
		else {
			pp->GreenLight();
		}

		if (pp->IsImpact()) {
			cout << "\a";
			pp->ScoreBoard(false);
			alive = false;
			break;

		}

		Sleep(100 / pp->getSpeed());
	}
}