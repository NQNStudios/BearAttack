#include "GameState.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "GameOverState.h"

#include "Game.h"

bears::GameState::GameState(Game* game)
    : game(game)
{
    player = new Player();

    bears.push_back(new Bear(true)); // right bear
    bears.push_back(new Bear(false)); // left bear

    for (int i = 0; i < 42; ++i)
    {
        kids.push_back(new Kid());
    }

    tileSprite = new Sprite({ 36, 244, 100, 100 }, 0, 0);
}

bears::GameState::~GameState()
{
    delete player;

    std::for_each(bears.begin(), bears.end(), [](Bear* bear){ delete bear; });
    std::for_each(kids.begin(), kids.end(), [](Kid* kid){ delete kid; });

}

void bears::GameState::Update(unsigned int deltaMS, bears::Input& input)
{
    player->Update(deltaMS, input);

    if (input.IsLeftMouseClicked())
    {
        (*(--bears.end()))->Attack(input.MouseX(), input.MouseY());
    }
    else if (input.IsRightMouseClicked())
    {
        (*(bears.begin()))->Attack(input.MouseX(), input.MouseY());
    }

    std::for_each(kids.begin(), kids.end(),
            [this, deltaMS](Kid* kid)
            {
                kid->Update(deltaMS, player);

                Sprite* bearOne = bears[false]->GetSprite();
                Sprite* bearTwo = bears[true]->GetSprite();
                Sprite* playerSprite = player->GetSprite();

                Sprite* kidSprite = kid->GetSprite();

                if (kidSprite->Collision(playerSprite))
                {
                    // TODO kill player 
                    this->gameOver(false);

                }

                if (kidSprite->Collision(bearOne) || kidSprite->Collision(bearTwo))
                {
                    // TODO kill kid
                    std::cout << "killed a kid" << std::endl;
                }
            });

    std::for_each(bears.begin(), bears.end(),
            [this, deltaMS](Bear* bear){
                bear->Update(player, deltaMS);

            });

    // TODO check for dead kids
}

void bears::GameState::Draw(bears::Graphics& graphics)
{
    // draw tiles everywhere!!
    for (int y = 0; y < 720; y += 100)
    {
        int start_x = 0;
        if ((y / 100) % 2 == 1) start_x = -50;

        for (int x = start_x; x < 1280; x += 100)
        {
            tileSprite->SetX(x);
            tileSprite->SetY(y);
            tileSprite->Draw(graphics);
        }
    }


    player->Draw(graphics);

    std::for_each(kids.begin(), kids.end(),
            [&graphics](Kid* kid){ kid->Draw(graphics); });
    std::for_each(bears.begin(), bears.end(),
            [&graphics](Bear* bear){ bear->Draw(graphics); });
}

void bears::GameState::gameOver(bool win)
{
    game->SetState(new GameOverState(win));
}
