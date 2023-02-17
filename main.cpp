#include <iostream>
#include "player.hpp"
#include "deck.hpp"

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
bool playerTurn(Deck &deck, Player &player)
{
    while (true)
    {
        if (player.isBust())
        {
            // This can happen even before the player had a choice if they drew 2
            // aces.
            std::cout << "You busted!\n";
            return true;
        }
        else
        {
            if (playerWantsHit())
            {
                Card *playerCard = &player.drawCard(deck);
                std::cout << "You were dealt a ";
                playerCard->print();
                std::cout << " and now have " << player.score() << '\n';
            }
            else
            {
                // The player didn't go bust.
                return false;
            }
        }
    }
    return false;
}

// Returns true if the dealer went bust. False otherwise.
bool dealerTurn(Deck &deck, Player &dealer)
{
    while (dealer.score() < Player::MIN_SCORE)
    {
        Card *dealerCard = &dealer.drawCard(deck);
        std::cout << "The dealer turned up a ";
        dealerCard->print();
        std::cout << " and now has " << dealer.score() << '\n';
    }

    if (dealer.isBust())
    {
        std::cout << "The dealer busted!\n";
        return true;
    }
    return false;
}

bool playBlackjack(Deck &deck)
{
    Player dealer{};
    dealer.drawCard(deck);

    std::cout << "The dealer is showing: " << dealer.score() << '\n';

    Player player{};
    player.drawCard(deck);
    player.drawCard(deck);

    std::cout << "You have: " << player.score() << '\n';

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
