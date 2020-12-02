
#include"Traffic_Light.h"


int main(){
	resizeText(20, 20);
	
	FixConsoleWindow();
	hidecursor();
	Lights li;
	li.RedLight(8, 10);
	li.GreenLight(8, 15);
	li.YellowLight(8, 20);

	mciSendString("play WeWillRockYou.mp3 repeat", NULL, 0, NULL);	
	system("pause >nul");


    return 0;
}