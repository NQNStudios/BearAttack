#pragma once

#include <map>
#include <vector>
#include <string>

#include "Game.h"
#include "State.h"

namespace bears
{
    class GameState : public State
    {
        public:
            GameState(Game* game);

            void Update(const unsigned int deltaMS, Input& input);
            void Draw(Graphics& graphics);

        private:
            Game* game;

            void gameOver();
    };
}
