#pragma once

#include <vector>

#include "SDL.h"

#include "Sprite.h"
#include "Player.h"
#include "Graphics.h"

namespace bears
{
    class Kid
    {
        public:
            Kid();

            void Update(int deltaMS, Player* player);
            void Draw(bears::Graphics& graphics);

            Sprite* GetSprite() { return sprite; }

        private:
            static std::vector<SDL_Rect> sources;
            Sprite* sprite;
    };
}
