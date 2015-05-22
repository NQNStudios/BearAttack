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
    TTF_Init();

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

    mFont = TTF_OpenFont("assets/fonts/Courgette-Regular.ttf", 24);

    SDL_Surface* sheetSurface = IMG_Load("assets/textures/spritesheet.png");
    mSpritesheet = SDL_CreateTextureFromSurface(mRenderer, sheetSurface);
    SDL_FreeSurface(sheetSurface);

}

bears::Graphics::~Graphics()
{
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    SDL_DestroyTexture(mSpritesheet);

    for (auto it = textGlyphs.begin(); it != textGlyphs.end(); ++it)
    {
        SDL_DestroyTexture(it->second);
    }

    TTF_CloseFont(mFont);

    IMG_Quit();
    TTF_Quit();
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

void bears::Graphics::RenderText(std::string text)
{
    SDL_Color color = { 255, 255, 255, 255 };
    SDL_Surface* tempSurf = TTF_RenderText_Solid(mFont, text.c_str(), color);
    textGlyphs[text] = SDL_CreateTextureFromSurface(mRenderer, tempSurf);

    SDL_FreeSurface(tempSurf);
}

void bears::Graphics::DrawText(std::string text, int x, int y)
{
    SDL_Texture* texture = textGlyphs[text];

    SDL_Rect destRect;
    destRect.x = x;
    destRect.y = y;
    TTF_SizeText(mFont, text.c_str(), &destRect.w, &destRect.h);

    SDL_RenderCopy(mRenderer, texture, NULL, &destRect);
}

void bears::Graphics::DrawSprite(SDL_Rect source, int x, int y)
{
    SDL_Rect destRect;
    destRect.x = x;
    destRect.y = y;
    destRect.w = source.w;
    destRect.h = source.h;

    SDL_RenderCopy(mRenderer, mSpritesheet, &source, &destRect);
}
