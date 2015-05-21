#pragma once

#include "SDL.h"

#include "Graphics.h"

namespace bears
{
    class Sprite
    {
        public:
            Sprite(SDL_Rect source_rect, int x, int y);

            bool Collision(Sprite* other);

            void Draw(Graphics& graphics);

            void Move(int dx, int dy);
        private:
            SDL_Rect source_rect;
            int x;
            int y;

            int left() { return x; }
            int right() { return x + source_rect.w; }
            int top() { return y + source_rect.h / 6; }
            int bottom() { return y + source_rect.h; }
    };
}
