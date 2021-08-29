

#include"SDL2/SDL.h"
#include "Screen.h"

using namespace std;
using namespace tbg;

int main(int argcount, char **args) {

	Screen screen;


	while (true) {
		if (screen.Main_Loop() == false) {
			break;
		}

	}

	screen.Cleanup();

	return 0;
}
