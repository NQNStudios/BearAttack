#include "IntroState.h"

#include <string>

namespace
{
    const std::string INTRO_TEXT(
            "And he went up from thence unto Bethel:       \n" +
            "and as he was going up by the way,            \n" +
            "there came forth little children out          \n" +
            "of the city, and mocked him, and said         \n" +
            "unto him, Go up, thou bald head; go up,       \n" +
            "thou bald head.                               \n" +
            "                                              \n" +
            "And he turned back, and looked on them,       \n" +
            "and cursed them in the name of the LORD.      \n" +
            "And there came forth two she bears out        \n" +
            "of the wood, and tare forty and two           \n" +
            "children of them.                             \n" +
            "                                              \n" +
            "And he went from thence to mount Carmel,      \n" +
            "and from thence he returned to Samaria.       \n" +
            "                                              \n" +
            "                                              \n" +
            "2 Kings 2:23-25                               \n" +
            "The King James Bible"
            );

    const int SCROLL_MS = 1000 * 30;
    const int SCROLL_MULTIPLIER = 3;
}

namespace bears
{
    IntroState::IntroState(Game* game)
        : game(game)
    {

    }
}
