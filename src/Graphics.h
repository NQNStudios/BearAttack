#pragma once

#include <map>
#include <string>

#include "SDL.h"
#include "SDL_ttf.h"

namespace bears
{
    class Graphics
    {
        public:
            Graphics();
            ~Graphics();

            void Clear();
            void Update();

            void RenderText(std::string text);

            void DrawText(std::string text, int x, int y);
        private:
            SDL_Window* mWindow;
            SDL_Renderer* mRenderer;

            SDL_Texture* mSpritesheet;
            TTF_Font* mFont;

            std::map<std::string, SDL_Texture*> textGlyphs;
    };
}
