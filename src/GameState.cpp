#include "GameState.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "Game.h"

bears::GameState::GameState(Game* game)
    : game(game)
{
    player = new Player();

    bears.push_back(new Bear(true));
    bears.push_back(new Bear(false));
}

bears::GameState::~GameState()
{
    delete player;

    std::for_each(bears.begin(), bears.end(), [](Bear* bear){ delete bear; });
}

void bears::GameState::Update(unsigned int deltaMS, bears::Input& input)
{
    player->Update(deltaMS, input);

    std::for_each(bears.begin(), bears.end(),
            [this, deltaMS](Bear* bear){ bear->Update(player, deltaMS); });
}

void bears::GameState::Draw(bears::Graphics& graphics)
{
    player->Draw(graphics);

    std::for_each(bears.begin(), bears.end(),
            [&graphics](Bear* bear){ bear->Draw(graphics); });
}

void bears::GameState::gameOver()
{
}
