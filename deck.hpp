#pragma once
#include <vector>
#include "card.hpp"

class Deck
{
private:
    static const int DECK_SIZE{52};
    std::vector<Card> m_deck{};
    int m_cardIndex{0};

    void setup();

public:
    Deck();
    void print();
    Deck shuffle();
    Card &dealCard();
};