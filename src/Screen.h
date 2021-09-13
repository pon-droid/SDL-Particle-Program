/*
 * Screen.h
 *
 *  Created on: 29 Aug 2021
 *      Author: tp
 */

#ifndef SCREEN_H_
#define SCREEN_H_
#include<SDL2/SDL.h>
#include<iomanip>
#include<math.h>

namespace tbg {

class Screen {
public:
	const static int SCREEN_WIDTH = 1400;
	const static int SCREEN_HEIGHT = 1050;
private:
	SDL_Window *mainwindow;
	SDL_Renderer *mainrenderer;
	SDL_Texture *maintexture;
	Uint32 *buffer1;
	Uint32 *buffer2;
public:
	Screen();
	bool Init();
	void Set_Pixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue,
			Uint8 alpha);
	bool Main_Loop();
	void BoxBlur();
	void Update();
	void Cleanup();


};

} /* namespace tbg */

#endif /* SCREEN_H_ */
