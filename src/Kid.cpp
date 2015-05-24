#include "Kid.h"

#include <stdlib.h>
#include <time.h>

namespace
{
    const float SPEED = 400.0f;
}
namespace bears
{
    // static
    std::vector<SDL_Rect> Kid::sources;

    Kid::Kid()
    {
        if (sources.empty())
        {
            srand(time(NULL));
            // fill sources
            sources.push_back({ 475, 49, 25, 44 });
            sources.push_back({ 507, 49, 25, 44 });
            sources.push_back({ 537, 49, 25, 44 });
            sources.push_back({ 569, 48, 25, 45 });
        }

        int sprite_num = rand() % sources.size();

        // start position generation from the center
        int x = 1280 / 2;
        int y = 720 / 2;

        // add random amounts to either coordinate
        int dx = (rand() % 5000) + 1280 / 2;
        if (rand() % 2 == 1) dx *= -1;
        
        int dy = (rand() % 5000) + 720 / 2;
        if (rand() % 2 == 1) dy *= -1;

        x += dx;
        y += dy;
        sprite = new Sprite(sources[sprite_num], x, y);
    }

    void Kid::Update(int deltaMS, Player* player)
    {
        // move towards the player{
        int x = sprite->GetX();
        int y = sprite->GetY();
        if (true)
        {
            x = sprite->GetCenterX();
            y = sprite->GetCenterY();
        }
        // move to target
        float dx = player->GetCenterX() - x;
        float dy = player->GetCenterY() - y;

        float d = sqrt((float)(dx * dx) + (float)(dy * dy));

        dx /= d;
        dy /= d;

        dx *= SPEED;
        dy *= SPEED;

        dx *= (float)((float)deltaMS / 1000.0f);
        dy *= (float)((float)deltaMS / 1000.0f);

        sprite->Move((int)dx, (int)dy);
    }

    void Kid::Draw(Graphics& graphics)
    {
        sprite->Draw(graphics);
    }
}
