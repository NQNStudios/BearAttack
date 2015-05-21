#include "Bear.h"

namespace
{
    const int DISTANCE = 100;
    const int Y_OFFS = 50;

    const int SPEED = 650;
}

namespace bears
{
    Bear::Bear(bool side)
        : side(side), attacking(false),
            targetX(0), targetY(0), attached(true)
    {
        int x = 1280/2 - 40;
        int y = 720/2 - 60;

        if (side)
        {
            // right side
            x += DISTANCE;
        }
        else
        {
            // other side
            x -= DISTANCE;
        }

        y -= Y_OFFS;

        sprite = new Sprite({ 130, 20, 122, 176}, x, y);
        meanSprite = new Sprite({ 278, 24, 122, 176 }, x, y);
    }

    Bear::~Bear()
    {
        delete sprite;
        delete meanSprite;
    }

    void Bear::Update(Player* player, int deltaMS)
    {
        if (attached)
        {
            // follow player pos
            int x = player->GetX();
            int y = player->GetY();
            if (side)
            {
                // right side
                
                x += DISTANCE;
            }
            else
            {
                // left side
                x -= DISTANCE;
            }

            y -= Y_OFFS;

            sprite->SetX(x);
            sprite->SetY(y);
            meanSprite->SetX(x);
            meanSprite->SetY(y);
        }
        else if (attacking)
        {
            // move to target
            int dx = targetX - sprite->GetX();
            int dy = targetY - sprite->GetY();

            float d = sqrt((float)(dx * dx) + (float)(dy * dy));

            dx /= d;
            dy /= d;

            dx *= SPEED;
            dy *= SPEED;

            dx *= (float)(deltaMS / 1000.0f);
            dy *= (float)(deltaMS / 1000.0f);

            sprite->Move(dx, dy);
            meanSprite->Move(dx, dy);
        }
        else
        {
            // move back to attachment
            // TODO not like this
            attached = true;
        }
    }

    void Bear::Draw(Graphics& graphics)
    {
        if (attacking)
        {
            meanSprite->Draw(graphics);
        }
        else
        {
            sprite->Draw(graphics);
        }
    }

    void Bear::Attack(int x, int y)
    {
        targetX = x;
        targetY = y;
        attacking = true;
        attached = false;
    }
}
