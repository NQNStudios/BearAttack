#pragma once

#include "Graphics.h"
#include "Input.h"
#include "Sprite.h"

namespace bears
{
    class Player
    {
        public:
            Player();
            ~Player();

            void Update(int deltaMS, Input& input);
            void Draw(Graphics& graphics);

            int GetX() { return sprite->GetX(); }
            int GetY() { return sprite->GetY(); }
        private:
            Sprite* sprite;
    };
}
