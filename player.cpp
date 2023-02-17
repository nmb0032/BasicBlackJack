#include "player.hpp"
#include "deck.hpp"
#include <iostream>

Card &Player::drawCard(Deck &deck)
{
    Card *card = &deck.dealCard();
    m_score += card->getValue();
    return *card;
}

int Player::score()
{
    return m_score;
}

bool Player::isBust()
{
    return (m_score > MAX_SCORE) ? true : false;
}