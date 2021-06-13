#include <algorithm>
#include <array>
#include <cassert>
#include <ctime>
#include <iostream>
#include <random>

class Card
{
public:
    enum class Suit
    {
        SUIT_CLUB,
        SUIT_DIAMOND,
        SUIT_HEART,
        SUIT_SPADE,

        MAX_SUITS
    };
    enum class Rank
    {
        RANK_2,
        RANK_3,
        RANK_4,
        RANK_5,
        RANK_6,
        RANK_7,
        RANK_8,
        RANK_9,
        RANK_10,
        RANK_JACK,
        RANK_QUEEN,
        RANK_KING,
        RANK_ACE,

        MAX_RANKS
    };
    Card(Rank r, Suit s)
        : rank(r)
        , suit(s)
    {}
    Card() = default;
    void print() const
    {
        switch (rank)
        {
        case Rank::RANK_2:
            std::cout << '2';
            break;
        case Rank::RANK_3:
            std::cout << '3';
            break;
        case Rank::RANK_4:
            std::cout << '4';
            break;
        case Rank::RANK_5:
            std::cout << '5';
            break;
        case Rank::RANK_6:
            std::cout << '6';
            break;
        case Rank::RANK_7:
            std::cout << '7';
            break;
        case Rank::RANK_8:
            std::cout << '8';
            break;
        case Rank::RANK_9:
            std::cout << '9';
            break;
        case Rank::RANK_10:
            std::cout << 'T';
            break;
        case Rank::RANK_JACK:
            std::cout << 'J';
            break;
        case Rank::RANK_QUEEN:
            std::cout << 'Q';
            break;
        case Rank::RANK_KING:
            std::cout << 'K';
            break;
        case Rank::RANK_ACE:
            std::cout << 'A';
            break;
        default:
            std::cout << '?';
            break;
        }
        switch (suit)
        {
        case Suit::SUIT_CLUB:
            std::cout << 'C';
            break;
        case Suit::SUIT_DIAMOND:
            std::cout << 'D';
            break;
        case Suit::SUIT_HEART:
            std::cout << 'H';
            break;
        case Suit::SUIT_SPADE:
            std::cout << 'S';
            break;
        default:
            std::cout << '?';
            break;
        }
    }
    int value() const
    {
        if (rank <= Rank::RANK_10)
        {
            return (static_cast<int>(rank) + 2);
        }
        switch (rank)
        {
        case Rank::RANK_JACK:
        case Rank::RANK_QUEEN:
        case Rank::RANK_KING:
            return 10;
        case Rank::RANK_ACE:
            return 11;
        default:
            assert(false && "should never happen");
            return 0;
        }
    }
private:
    Rank rank{};
    Suit suit{};
};

class Deck
{
    using deck_t = std::array<Card, 52>;
    using index_t = deck_t::size_type;
public:
    Deck()
    {
        index_t card{ 0 };

        auto suits{ static_cast<index_t>(Card::Suit::MAX_SUITS) };
        auto ranks{ static_cast<index_t>(Card::Rank::MAX_RANKS) };

        for (index_t suit{ 0 }; suit < suits; ++suit)
        {
            for (index_t rank{ 0 }; rank < ranks; ++rank)
            {
                deck[card] = { static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit) };
                ++card;
            }
        }
    }
    void print() const
    {
        for (const auto& card : deck)
        {
            card.print();
            std::cout << ' ';
        }

        std::cout << '\n';
    }
    void shuffle()
    {
        static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
        std::shuffle(deck.begin(), deck.end(), mt);
    }
    const Card& dealCard()
    {
        return deck[m_cardIndex++];
    }
private:
    deck_t deck{};
    index_t m_cardIndex{ 0 };
};

class Player
{
public:
    void drawCard(Deck& deck)
    {
        m_score += deck.dealCard().value();
    }
    int score()
    {
        return m_score;
    }
    bool isBust()
    {
        return m_score > maximumScore;
    }
private:
    int m_score{ 0 };
    const int maximumScore{ 21 };
};

bool playerWantsHit()
{
    while (true)
    {
        std::cout << "(h) to hit, or (s) to stand: ";

        char ch{};
        std::cin >> ch;

        switch (ch)
        {
        case 'h':
            return true;
        case 's':
            return false;
        }
    }
}

// Returns true if the player went bust. False otherwise.
bool playerTurn(Deck& deck, Player& player)
{
    while (true)
    {
        std::cout << "You have: " << player.score() << '\n';

        if (player.isBust())
        {
            return true;
        }
        else
        {
            if (playerWantsHit())
            {
                player.drawCard(deck);
            }
            else
            {
                // The player didn't go bust.
                return false;
            }
        }
    }
}

// Returns true if the dealer went bust. False otherwise.
bool dealerTurn(Deck& deck, Player& dealer)
{
    while (dealer.score() < 17)
    {
        dealer.drawCard(deck);
    }

    return dealer.isBust();
}

bool playBlackjack(Deck& deck)
{
    Player dealer{ };
    dealer.drawCard(deck);

    std::cout << "The dealer is showing: " << dealer.score() << '\n';

    Player player{ };
    player.drawCard(deck);
    player.drawCard(deck);

    if (playerTurn(deck, player))
    {
        return false;
    }

    if (dealerTurn(deck, dealer))
    {
        return true;
    }

    return (player.score() > dealer.score());
}

int main()
{
    Deck deck{};
    deck.shuffle();

    if (playBlackjack(deck))
    {
        std::cout << "You win!\n";
    }
    else
    {
        std::cout << "You lose!\n";
    }

    return 0;
}