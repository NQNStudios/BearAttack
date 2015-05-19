#include "Graphics.h"

#include <iostream>

#include "SDL_image.h"

#include "Game.h"

namespace
{
    const unsigned int RESOLUTION_WIDTH = 1280;
    const unsigned int RESOLUTION_HEIGHT = 720;
}

bears::Graphics::Graphics()
{
    int flags = IMG_INIT_PNG;
    IMG_Init(flags);

    unsigned int windowWidth = 0;
    unsigned int windowHeight = 0;
    SDL_WindowFlags windowFlags = SDL_WINDOW_SHOWN;

#ifdef NDEBUG
    windowFlags = SDL_WINDOW_FULLSCREEN_DESKTOP;
#else
    windowWidth = RESOLUTION_WIDTH;
    windowHeight = RESOLUTION_HEIGHT;
#endif

    mWindow = SDL_CreateWindow("She Bear Attack", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, windowFlags);

    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);

    SDL_RenderSetLogicalSize(mRenderer, RESOLUTION_WIDTH, RESOLUTION_HEIGHT);
    SDL_SetRenderDrawBlendMode(mRenderer, SDL_BLENDMODE_BLEND);
}

bears::Graphics::~Graphics()
{
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);

    IMG_Quit();
}

void bears::Graphics::Clear()
{
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
    SDL_RenderClear(mRenderer);
}

void bears::Graphics::Update()
{
    SDL_RenderPresent(mRenderer);
}

//void bears::Graphics::LoadSpritesheet(std::string key, const char* path)
//{
    //SDL_Surface* sheetSurface = IMG_Load(path);
    //mSpritesheets[key] = SDL_CreateTextureFromSurface(mRenderer, sheetSurface);

    //SDL_FreeSurface(sheetSurface); // clean up
//}
