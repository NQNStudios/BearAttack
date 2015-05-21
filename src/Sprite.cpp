#include "Sprite.h"

namespace bears
{
    Sprite::Sprite(SDL_Rect source_rect, int x, int y)
        : source_rect(source_rect), x(x), y(y)
    {
    }

    bool Sprite::Collision(Sprite* other)
    {
        if (this->left() > other->right()) return false;
        if (this->right() < other->left()) return false;
        if (this->top() > other->bottom()) return false;
        if (this->bottom() < other->top()) return false;

        return true;
    }

    void Sprite::Move(int dx, int dy)
    {
        this->x += dx;
        this->y += dy;
    }

    void Sprite::Draw(Graphics& graphics)
    {
        graphics.DrawSprite(source_rect, x, y);
    }

}
