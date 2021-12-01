#ifndef HAND_H
#define HAND_H
#include "Card.h"
#include "Deck.h"
#include <vector>

using namespace std;

class Hand
{
    public:
        Hand(Deck*& myDeck);
        void drawHand();
        void drawNewCard(int cardPosition, Deck*& myDeck);
        void sortHand();
        int checkPayout();
        string getHandResult();
    private:
        std::vector<Card> myHand;
        string handResult;
        void setHandResult(string handResult);
};

#endif