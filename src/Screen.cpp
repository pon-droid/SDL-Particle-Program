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
	SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
	mainrenderer = SDL_CreateRenderer(mainwindow, -1,
			SDL_RENDERER_PRESENTVSYNC);
	maintexture = SDL_CreateTexture(mainrenderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
	buffer1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
	buffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

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

	//Set each pixel in buffer to black
	memset(buffer1, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
	memset(buffer2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

	return true;
}

void Screen::Update() {
	SDL_UpdateTexture(maintexture, NULL, buffer1,
			SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(mainrenderer);
	SDL_RenderCopy(mainrenderer, maintexture, NULL, NULL);
	SDL_RenderPresent(mainrenderer);
}

void Screen::BoxBlur() {
	Uint32 *tempbuff = buffer1;
	buffer1 = buffer2;
	buffer2 = tempbuff;

	for (int y = 0; y < SCREEN_HEIGHT; y++) {
		for (int x = 0; x < SCREEN_WIDTH; x++) {

			int redTotal = 0;
			int greenTotal = 0;
			int blueTotal = 0;

			for (int row = -1; row <= 1; row++) {
				for (int col = -1; col <= 1; col++) {
					int currentX = x + col;
					int currentY = y + row;

					if (currentX >= 0 && currentX < SCREEN_WIDTH
							&& currentY >= 0 && currentY < SCREEN_HEIGHT) {
						Uint32 colour = buffer2[currentY * SCREEN_WIDTH
								+ currentX];

						Uint8 red = colour >> 24;
						Uint8 green = colour >> 16;
						Uint8 blue = colour >> 8;

						redTotal += red;
						greenTotal += green;
						blueTotal += blue;
					}

				}
			}
			Uint8 red = redTotal / 9;
			Uint8 green = greenTotal / 9;
			Uint8 blue = blueTotal / 9;

			Set_Pixel(x, y, red, green, blue, 0xFF);
		}
	}
}

void Screen::Set_Pixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue,
		Uint8 alpha) {

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
		return;
	}

	Uint32 colour = 0;

	colour += red;
	colour <<= 8;
	colour += green;
	colour <<= 8;
	colour += blue;
	colour <<= 8;
	colour += alpha;

	buffer1[(y * SCREEN_WIDTH) + x] = colour;
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
	delete[] buffer1;
	delete[] buffer2;
	SDL_DestroyRenderer(mainrenderer);
	SDL_DestroyTexture(maintexture);
	SDL_DestroyWindow(mainwindow);
	SDL_Quit();
}

} /* namespace tbg */
