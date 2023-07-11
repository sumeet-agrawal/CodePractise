#ifndef CARDS_CONSTANTS
#define CARDS_CONSTANTS

namespace Cards
{
    enum class ranks
    {
          two
        , three
        , four
        , five
        , six
        , seven
        , eight
        , nine
        , ten
        , jack
        , queen
        , king
        , ace

        , max_ranks
    };

    enum class suits
    {
          clubs
        , diamonds
        , hearts
        , spades

        , max_suits
    };

    enum class BlackJackResult
    {
          player_win
        , dealer_win
        , tie
    };

    constexpr int g_maxScore{21};
    constexpr int g_minDealerScore{17};
    constexpr int g_decreaseAceScore{10};
}

#endif