#pragma once

#include "Sprite.h"
#include "Graphics.h"
#include "Player.h"

namespace bears
{
    class Bear
    {
        public:
            Bear(bool side);
            ~Bear();

            void Update(Player* player, int deltaMS);
            void Draw(Graphics& graphics);
            void Attack(int x, int y);
            Sprite* GetSprite() { return sprite; }
        private:
            Sprite* sprite;
            Sprite* meanSprite;

            bool side;

            int targetX;
            int targetY;
            
            bool attacking;
            bool attached;

            bool MoveToTarget(int deltaMS, bool centered);
            int GetFollowX(Player* player);
            int GetFollowY(Player* player);
    };
}
