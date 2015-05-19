#pragma once

#include "Graphics.h"
#include "Input.h"
#include "State.h"

namespace bears
{
    class Game
    {
        public:
            Game();
            ~Game();

            void Run();
            void Quit() { mRunning = false; }

            void SetState(State* state) {
                if (mState)
                {
                    delete mState;
                }
                mState = state;
            }

        private:
            void LoadContent(Graphics& graphics);
            void Update(int deltaMS, Input& input);
            void Draw(Graphics& graphics);

            State* mState;

            bool mRunning;
    };
}
