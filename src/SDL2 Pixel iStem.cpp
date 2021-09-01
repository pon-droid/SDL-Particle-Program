#include"SDL2/SDL.h"
#include "Screen.h"
#include<Math.h>
#include<iostream>

using namespace std;
using namespace tbg;

int main(int argcount, char **args) {

	Screen screen;

	while (true) {
		int ticks = SDL_GetTicks();
		//Sine locks value to -1 +1 and gradually bounces up and down
		//unsigned is there to ensure we do not receive a negative integer

		unsigned char red = (1+(sin(ticks*0.0002)))*128;
		unsigned char green = (1+(sin(ticks*0.0001)))*128;
		unsigned char blue = (1+(sin(ticks*0.0003)))*128;

		for(int y=0;y<Screen::SCREEN_HEIGHT;y++){
			for(int x=0;x<Screen::SCREEN_WIDTH;x++){
				screen.Set_Pixel(x,y,red,green,blue,255);
			}
		}



		screen.Update();

		if (screen.Main_Loop() == false) {
			break;
		}

	}

	screen.Cleanup();

	return 0;
}
