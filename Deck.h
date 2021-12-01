#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <vector>

using namespace std;

class Deck
{
    public:
        Deck();
        Card drawCard();
        void shuffleDeck();
        int getDeckSize();
        int getNumSuits();
        int getNumRanks();
    private:
        std::vector<Card> myDeck;
        int topCard;
};
#endif