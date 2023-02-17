#include "deck.hpp"
#include "card.hpp"
#include <vector>
#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>

Deck::Deck()
{
    setup();
}

void Deck::setup()
{
    m_deck.reserve(DECK_SIZE);
    for (int i{0}; i < static_cast<int>(Card::Suit::max_suit); i++)
    {
        for (int j{0}; j < static_cast<int>(Card::Rank::max_rank); j++)
        {
            m_deck.emplace_back(Card{static_cast<Card::Rank>(j), static_cast<Card::Suit>(i)});
        }
    }
}

void Deck::print()
{
    for (const auto &card : m_deck)
    {
        card.print();
        std::cout << ' ';
    }
    std::cout << " Size: " << m_deck.size() << std::endl;
}

Deck Deck::shuffle()
{
    m_cardIndex = 0;
    static std::mt19937 gen{static_cast<std::mt19937::result_type>(std::time(nullptr))};
    std::shuffle(m_deck.begin(), m_deck.end(), gen);
    return *this;
}

Card &Deck::dealCard()
{
    return m_deck[m_cardIndex++];
}
