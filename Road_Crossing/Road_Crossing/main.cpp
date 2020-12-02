
#include"Traffic_Light.h"


int main(){
	resizeText(20, 20);
	
	FixConsoleWindow();
	hidecursor();
	Lights li;
	li.RedLight(8, 10);
	li.GreenLight(8, 15);
	li.YellowLight(8, 20);
    return 0;
}