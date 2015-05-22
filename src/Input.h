#pragma once

#include <map>

#include "SDL.h"

namespace bears
{
    class Input
    {
        public:
            Input()
                : mQuitEvent(false), mouseX(0), mouseY(0),
                leftMouseDown(false), wasLeftMouseDown(false),
                rightMouseDown(false), wasRightMouseDown(false)
            {
            }

            void Update();

            bool IsKeyPressed(SDL_Keycode key);
            bool IsKeyReleased(SDL_Keycode key);
            bool IsKeyHeld(SDL_Keycode key);
            bool IsAnyKeyHeld();
            bool IsAnyKeyPressed();

            bool IsLeftMouseClicked();
            bool IsRightMouseClicked();
            int MouseX() { return mouseX; }
            int MouseY() { return mouseY; }

            bool WasQuitEvent() { return mQuitEvent; }

        private:
            std::map<SDL_Keycode, bool> mHeldKeys;
            std::map<SDL_Keycode, bool> mPressedKeys;
            std::map<SDL_Keycode, bool> mReleasedKeys;

            int mouseX, mouseY;
            bool leftMouseDown;
            bool wasLeftMouseDown;

            bool rightMouseDown;
            bool wasRightMouseDown;

            bool mQuitEvent;
    };
}
