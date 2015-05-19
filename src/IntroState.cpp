#include "IntroState.h"

#include <iostream>
#include <string>

#include "SDL.h"

#include "GameState.h"

namespace
{
    const int SCROLL_MS = 1000 * 30;
    const int SCROLL_MULTIPLIER = 10;

    const int START_Y = 720;
    const int FINISH_Y = 40;

}

namespace bears
{
    IntroState::IntroState(Game* game)
        : game(game), elapsedMS(0), scrollMS(SCROLL_MS), loaded(false),
        finishedAnimating(false)
    {
        std::cout << "Making an intro state" << std::endl;
        text.push_back("And he went up from thence unto Bethel:");
        text.push_back("and as he was going up by the way,");
        text.push_back("there came forth little children out");
        text.push_back("of the city, and mocked him, and said");
        text.push_back("unto him, Go up, thou bald head; go up,");
        text.push_back("thou bald head.");
        text.push_back("");
        text.push_back("And he turned back, and looked on them,");
        text.push_back("and cursed them in the name of the LORD.");
        text.push_back("And there came forth two she bears out");
        text.push_back("of the wood, and tare forty and two");
        text.push_back("children of them.");
        text.push_back("");
        text.push_back("And he went from thence to mount Carmel,");
        text.push_back("and from thence he returned to Samaria.");
        text.push_back("");
        text.push_back("");
        text.push_back("2 Kings 2:23-25");
        text.push_back("The King James Bible");

    }

    void IntroState::Update(const unsigned int deltaMS, Input& input)
    {
        int dms = deltaMS;
        if (input.IsAnyKeyHeld())
        {
            dms *= SCROLL_MULTIPLIER;
        }

        if (!finishedAnimating)
        {
            elapsedMS += dms;
        }

        if (elapsedMS >= SCROLL_MS)
        {
            finishedAnimating = true;
        }

        if (finishedAnimating)
        {
            if (input.IsKeyPressed(SDLK_SPACE))
            {
                game->SetState(new GameState(game));
            }
        }
    }

    void IntroState::Draw(Graphics& graphics)
    {
        if (!loaded)
        {
            for (auto it = text.begin(); it != text.end(); ++it)
            {
                graphics.RenderText(*it);
            }

            loaded = true;
        }

        int textX = 72;
        int textY = START_Y;

        textY += (FINISH_Y - START_Y) * (float)((float)elapsedMS / (float)scrollMS);

        if (finishedAnimating)
        {
            textY = FINISH_Y;
        }

        for (auto it = text.begin(); it != text.end(); ++it)
        {
            graphics.DrawText(*it, textX, textY);
            textY += 28;
        }
    }
}
