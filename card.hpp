#pragma once

class Card
{
public:
    enum class Suit
    {
        club,
        diamond,
        heart,
        spade,
        max_suit
    };

    enum class Rank
    {
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,
        rank_ace,
        max_rank
    };

private:
    Suit m_suit{};
    Rank m_rank{};

public:
    Card(Rank rank, Suit suit);
    void print() const;
    int getValue() const;
    Rank getRank() const;
};