#include<iostream>
#include"SDL2/SDL.h"

using namespace std;


int main(int argc, char* argv[])
{
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    if(SDL_Init(SDL_INIT_VIDEO)<0)
    {
        cout << "Fail" << endl;
        return 1;
    }
    SDL_Window *mainwindow = SDL_CreateWindow("the PON gram",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);

    SDL_Renderer *mainrenderer = SDL_CreateRenderer(mainwindow,-1,SDL_RENDERER_PRESENTVSYNC);

    SDL_Texture *maintexture = SDL_CreateTexture(mainrenderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_STATIC,SCREEN_WIDTH,SCREEN_HEIGHT);

    if(mainwindow == NULL)
    {
        SDL_Quit();
        return 2;
    }
    if(mainrenderer == NULL){
        SDL_DestroyWindow(mainwindow);
        SDL_Quit();
        return 3;
    }
    if(maintexture == NULL){
        SDL_DestroyRenderer(mainrenderer);
        SDL_DestroyTexture(maintexture);
        SDL_Quit();
        return 4;
    }

    Uint32 *buffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];

    memset(buffer, 0xFF, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));

    SDL_UpdateTexture(maintexture,NULL,buffer,SCREEN_WIDTH*sizeof(Uint32));
    SDL_RenderClear(mainrenderer);
    SDL_RenderCopy(mainrenderer,maintexture,NULL,NULL);
    SDL_RenderPresent(mainrenderer);

    bool leave = false;

    SDL_Event event;

    while(leave != true)
    {
        //Update particles, check for events, etc.
        //Pretty much the loop of the program
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                leave = true;
                cout << "Quitted" << endl;

            }

        }
    }

    cout << "Success" << endl;

    SDL_DestroyRenderer(mainrenderer);
    SDL_DestroyTexture(maintexture);
    SDL_DestroyWindow(mainwindow);
    SDL_Quit();
    return 0;
}
