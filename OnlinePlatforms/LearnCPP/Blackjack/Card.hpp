#ifndef PLAYING_CARD
#define PLAYING_CARD

class Card
{
public:
    enum Rank
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
    enum Suit
    {
          clubs
        , diamonds
        , hearts
        , spades

        , max_suits
    };

    Card() = default;
    Card(Rank rank, Suit suit)
        : m_rank{rank}
        , m_suit{suit}
    {}

    void print() const;
    int value() const;
    Rank rank() const;
private:
    Rank m_rank{};
    Suit m_suit{};
};

#endif