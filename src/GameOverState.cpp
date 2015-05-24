#include "GameOverState.h"

#include "GameState.h"

namespace bears
{
    GameOverState::GameOverState(Game* game, bool win)
        : loaded(false), game(game), win(win)
    {
        if (win)
        {
            text = "Congratulations! You killed all of the children in the name of the LORD.";
        }
        else
        {
            text = "Game over!";
        }
    }

    void GameOverState::Update(const unsigned int deltaMS, Input& input)
    {
        if (input.IsAnyKeyPressed())
        {
            if (win)
                game->Quit();
            else
                game->SetState(new GameState(game));
        }
    }

    void GameOverState::Draw(Graphics& graphics)
    {
        if (!loaded)
        {
            loaded = true;

            graphics.RenderText(text);
        }

        graphics.DrawText(text, 40, 500);
    }
}
