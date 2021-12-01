#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Card {
    public:
        // list of suits as an enum
        enum class suit_t
        {
            Clubs = 1,
            Diamonds,
            Hearts,
            Spades
        };

        // list of ranks as an enum
        enum class rank_t
        {
            Two = 2,
            Three,
            Four,
            Five,
            Six,
            Seven,
            Eight,
            Nine,
            Ten,
            Jack,
            Queen,
            King,
            Ace
        };

        Card(suit_t suit, rank_t rank);
        Card(int suit, int rank);
        void printCard();
        void setSuit(suit_t suit);
        void setRank(rank_t rank);
        suit_t getSuit();
        string getSuitName();
        string getSuitSymbol();
        rank_t getRank();
        string getRankName();
        string getRankSymbol();
        void drawCard();
        friend bool operator< (Card& c1, Card& c2);
        friend bool operator> (Card& c1, Card& c2);
    private:
        suit_t cardSuit;
        rank_t cardRank;
};
#endif