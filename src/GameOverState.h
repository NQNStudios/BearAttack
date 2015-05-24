#pragma once

#include "State.h"
#include "Game.h"
#include "Graphics.h"


namespace bears
{
    class GameOverState : public State
    {
        public:
            GameOverState(Game* game, bool win);

            void Update(const unsigned int deltaMS, Input& input);
            void Draw(Graphics& graphics);

        private:
            Game* game;

            std::string text;

            bool loaded;
            bool win;
    };
}
