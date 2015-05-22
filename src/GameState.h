#pragma once

#include <map>
#include <vector>
#include <string>

#include "Game.h"
#include "State.h"

#include "Player.h"
#include "Bear.h"
#include "Sprite.h"

namespace bears
{
    class GameState : public State
    {
        public:
            GameState(Game* game);
            ~GameState();

            void Update(const unsigned int deltaMS, Input& input);
            void Draw(Graphics& graphics);

        private:
            Game* game;

            Player* player;
            std::vector<Bear*> bears;

            Sprite* tileSprite;

            void gameOver();
    };
}
