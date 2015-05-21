#include "Player.h"

#include "SDL.h"

namespace bears
{
    Player::Player()
    {
        sprite = new Sprite({16, 24, 80, 120}, 1280/2 - 40, 720/2 - 60);
    }

    Player::~Player()
    {
        delete sprite;
    }

    void Player::Update(int deltaMS, Input& input)
    {
        float dx = 0;
        float dy = 0;

        if (input.IsKeyHeld(SDLK_w))
        {
            dy = -1;
        }
        if (input.IsKeyHeld(SDLK_s))
        {
            dy = 1;
        }
        if (input.IsKeyHeld(SDLK_a))
        {
            dx = -1;
        }
        if (input.IsKeyHeld(SDLK_d))
        {
            dx = 1;
        }

        if (abs(dx) == 1 && abs(dy) == 1)
        {
            dx *= (float)(sqrt(2) / 2.0f);
            dy *= (float)(sqrt(2) / 2.0f);
        }

        int speed = 450;
        dx *= speed;
        dy *= speed;

        dx *= ((float)deltaMS / 1000.0f);
        dy *= ((float)deltaMS / 1000.0f);

        sprite->Move((int)dx, (int)dy);
    }

    void Player::Draw(Graphics& graphics)
    {
        sprite->Draw(graphics);
    }
}
