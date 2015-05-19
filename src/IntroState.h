#include <string>
#include <vector>

#include "Game.h"
#include "State.h"
#include "Input.h"
#include "Graphics.h"

namespace bears
{
    class IntroState : public State
    {
        public:
            IntroState(Game* game);

            void Update(const unsigned int deltaMS, Input& input);
            void Draw(Graphics& graphics);

        private:
            Game* game;

            int elapsedMS;
            int scrollMS;

            std::vector<std::string> text;
            bool loaded;
            bool finishedAnimating;
    };
}
