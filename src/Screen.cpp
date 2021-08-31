/*
 * Screen.cpp
 *
 *  Created on: 29 Aug 2021
 *      Author: tp
 */

#include "Screen.h"

namespace tbg {

Screen::Screen() {
	Init();

}

bool Screen::Init() {
	// data member creation
	mainwindow = SDL_CreateWindow("the PON gram", SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	mainrenderer = SDL_CreateRenderer(mainwindow, -1,
			SDL_RENDERER_PRESENTVSYNC);
	maintexture = SDL_CreateTexture(mainrenderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
	buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

	// NULL checking
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}
	if (mainwindow == NULL) {
		SDL_Quit();
		return false;
	}
	if (mainrenderer == NULL) {
		SDL_DestroyWindow(mainwindow);
		SDL_Quit();
		return false;
	}
	if (maintexture == NULL) {
		SDL_DestroyRenderer(mainrenderer);
		SDL_DestroyTexture(maintexture);
		SDL_Quit();
		return false;
	}

	// Visual Processing

	//Set each pixel to white with 0xFF
	memset(buffer, 0xFF, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
	//Overwrite screen with dark green value

	for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
		buffer[i] = 0x008000FF;
	}


	return true;
}

void Screen::Update() {
	SDL_UpdateTexture(maintexture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(mainrenderer);
	SDL_RenderCopy(mainrenderer, maintexture, NULL, NULL);
	SDL_RenderPresent(mainrenderer);
}

void Screen::Set_Pixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha){
	Uint32 colour = 0;

	    colour += red;
	    colour <<= 8;
	    colour += green;
	    colour <<= 8;
	    colour += blue;
	    colour <<=8;
	    colour += alpha;

	    buffer[(y*SCREEN_WIDTH)+x] = colour;
}

bool Screen::Main_Loop() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {

			return false;
		}
	}
	return true;
}

void Screen::Cleanup() {
	delete[] buffer;
	SDL_DestroyRenderer(mainrenderer);
	SDL_DestroyTexture(maintexture);
	SDL_DestroyWindow(mainwindow);
	SDL_Quit();
}

} /* namespace tbg */
