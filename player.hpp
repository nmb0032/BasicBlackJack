#pragma once
#include "card.hpp"
#include "deck.hpp"

class Player
{
private:
    int m_score{0};

public:
    static const int MIN_SCORE{17};
    static const int MAX_SCORE{21};
    Card &drawCard(Deck &deck);
    int score();
    bool isBust();
};