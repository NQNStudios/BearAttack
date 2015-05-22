#include "Bear.h"

namespace
{
    const int DISTANCE = 100;
    const int Y_OFFS = 50;

    const int SPEED = 650;

    const float TARGET_DIST = 25.0f;
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

    int Bear::GetFollowX(Player* player)
    {
        int x = player->GetX();
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

        return x;
    }

    int Bear::GetFollowY(Player* player)
    {
        int y = player->GetY();
        y -= Y_OFFS;

        return y;
    }

    void Bear::Update(Player* player, int deltaMS)
    {
        if (attached)
        {
            int x = GetFollowX(player);
            int y = GetFollowY(player);
            sprite->SetX(x);
            sprite->SetY(y);
            meanSprite->SetX(x);
            meanSprite->SetY(y);
        }
        else if (attacking)
        {
            // move to target. If reached...
            if (MoveToTarget(deltaMS, true))
            {
                attacking = false;
            }
        }
        else
        {
            // move back to attachment
            targetX = GetFollowX(player);
            targetY = GetFollowY(player);
            if (MoveToTarget(deltaMS, false))
            {
                attached = true;
            }
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
        if (!attacking && attached)
        {
            targetX = x;
            targetY = y;
            attacking = true;
            attached = false;
        }
    }

    bool Bear::MoveToTarget(int deltaMS, bool centered)
    {
        int x = sprite->GetX();
        int y = sprite->GetY();
        if (centered)
        {
            x = sprite->GetCenterX();
            y = sprite->GetCenterY();
        }
        // move to target
        float dx = targetX - x;
        float dy = targetY - y;

        float d = sqrt((float)(dx * dx) + (float)(dy * dy));

        dx /= d;
        dy /= d;

        dx *= SPEED;
        dy *= SPEED;

        dx *= (float)((float)deltaMS / 1000.0f);
        dy *= (float)((float)deltaMS / 1000.0f);

        sprite->Move((int)dx, (int)dy);
        meanSprite->Move((int)dx, (int)dy);

        return d <= TARGET_DIST;
    }
}
