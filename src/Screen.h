/*
 * Screen.h
 *
 *  Created on: 29 Aug 2021
 *      Author: tp
 */

#ifndef SCREEN_H_
#define SCREEN_H_
#include<SDL2/SDL.h>


namespace tbg {

class Screen {
public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;
private:
	SDL_Window *mainwindow;
	SDL_Renderer *mainrenderer;
	SDL_Texture *maintexture;
	Uint32 *buffer;
public:
	Screen();
	bool Init();
	bool Main_Loop();
	void Cleanup();

};

} /* namespace tbg */

#endif /* SCREEN_H_ */
