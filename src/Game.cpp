#include "Game.h"

#include <iostream>
#include <string>

#include "GameState.h"
#include "IntroState.h"

namespace
{
    const int TARGET_FPS = 60;
    const int TARGET_MS_PER_FRAME = 1000 / TARGET_FPS;
    const int MAX_MS_PER_FRAME = 5 * TARGET_MS_PER_FRAME;
}

bears::Game::Game()
    : mRunning(false), mState(NULL)
{
}

bears::Game::~Game()
{
}

void bears::Game::Run()
{
    mRunning = true;

    bears::Graphics graphics;
    bears::Input input;

    this->LoadContent(graphics);

    int lastMS = SDL_GetTicks();

    while (mRunning)
    {
        const int startMS = SDL_GetTicks();

        std::cout << "1" << std::endl;
        input.Update();

        const int currentMS = SDL_GetTicks();

        const int deltaMS = currentMS - lastMS;
        std::cout << "2" << std::endl;

        this->Update(std::min(deltaMS, MAX_MS_PER_FRAME), input);
        lastMS = currentMS;
        std::cout << "3" << std::endl;

        this->Draw(graphics);

        const int elapsedMS = SDL_GetTicks() - startMS;

        if (elapsedMS < TARGET_MS_PER_FRAME)
        {
            SDL_Delay(TARGET_MS_PER_FRAME - elapsedMS);
        }

        if (input.WasQuitEvent())
        {
            Quit();
        }
    }
}

void bears::Game::LoadContent(bears::Graphics& graphics)
{
    SetState(new IntroState(this));
}

void bears::Game::Update(int deltaMS, bears::Input& input)
{
    std::cout << "Updating" << std::endl;
    mState->Update(deltaMS, input);
    std::cout << "Done updating " << std::endl;
}

void bears::Game::Draw(bears::Graphics& graphics)
{
    std::cout << "Drawing " << std::endl;
    graphics.Clear();

    mState->Draw(graphics);

    graphics.Update();
    std::cout << "Done drawing " << std::endl;
}
