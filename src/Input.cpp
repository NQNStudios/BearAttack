#include "Input.h"

void bears::Input::Update()
{
    mPressedKeys.clear();
    mReleasedKeys.clear();

    wasLeftMouseDown = leftMouseDown;
    wasRightMouseDown = rightMouseDown;

    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                mQuitEvent = true;
                break;

            case SDL_KEYDOWN:
                if (!event.key.repeat)
                {
                    mPressedKeys[event.key.keysym.sym] = true;
                    mHeldKeys[event.key.keysym.sym] = true;
                }
                break;

            case SDL_KEYUP:
                if (!event.key.repeat)
                {
                    mReleasedKeys[event.key.keysym.sym] = true;
                    mHeldKeys[event.key.keysym.sym] = false;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                switch (event.button.button)
                {
                    case SDL_BUTTON_LEFT:
                        leftMouseDown = true;
                    case SDL_BUTTON_RIGHT:
                        rightMouseDown = true;
                }
                break;
            case SDL_MOUSEBUTTONUP:
                switch (event.button.button)
                {
                    case SDL_BUTTON_LEFT:
                        leftMouseDown = false;
                    case SDL_BUTTON_RIGHT:
                        rightMouseDown = false;
                }
                break;
            case SDL_MOUSEMOTION:
                mouseX = event.motion.x;
                mouseY = event.motion.y;
                break;
        }
    }
}

bool bears::Input::IsKeyPressed(SDL_Keycode key)
{
    return mPressedKeys[key];
}

bool bears::Input::IsKeyReleased(SDL_Keycode key)
{
    return mReleasedKeys[key];
}

bool bears::Input::IsKeyHeld(SDL_Keycode key)
{
    return mHeldKeys[key];
}

bool bears::Input::IsAnyKeyHeld()
{
    for (auto it = mHeldKeys.begin(); it != mHeldKeys.end(); ++it)
    {
        if (it->second)
        {
            return true;
        }
    }

    return false;
}

bool bears::Input::IsAnyKeyPressed()
{
    for (auto it = mPressedKeys.begin(); it != mPressedKeys.end(); ++it)
    {
        if (it-> second)
        {
            return true;
        }
    }

    return false;
}

bool bears::Input::IsLeftMouseClicked()
{
    return leftMouseDown && !wasLeftMouseDown;
}

bool bears::Input::IsRightMouseClicked()
{
    return rightMouseDown && !wasRightMouseDown;
}
