#include "GameState.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include "Game.h"

bears::GameState::GameState(Game* game)
    : game(game)
{
}

void bears::GameState::Update(unsigned int deltaMS, bears::Input& input)
{
}

void bears::GameState::Draw(bears::Graphics& graphics)
{
}
