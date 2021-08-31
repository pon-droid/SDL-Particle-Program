#include"SDL2/SDL.h"
#include "Screen.h"
#include<Math.h>
#include<iostream>

using namespace std;
using namespace tbg;

int main(int argcount, char **args) {

	Screen screen;

	while (true) {

		for(int y=0;y<Screen::SCREEN_HEIGHT;y++){
			for(int x=0;x<Screen::SCREEN_WIDTH;x++){
				screen.Set_Pixel(x,y,128,128,0,255);
			}
		}

		screen.Set_Pixel(400, 300, 255, 255, 255, 255);

		screen.Update();

		if (screen.Main_Loop() == false) {
			break;
		}

	}

	screen.Cleanup();

	return 0;
}
