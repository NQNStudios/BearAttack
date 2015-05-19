#pragma once

#include <map>
#include <string>

#include "SDL.h"

namespace bears
{
    class Graphics
    {
        public:
            Graphics();
            ~Graphics();

            void Clear();
            void Update();

        private:
            SDL_Window* mWindow;
            SDL_Renderer* mRenderer;

    };
}
