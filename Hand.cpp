#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Default constructor
Hand::Hand(Deck*& myDeck)
{
    for(int i = 0; i < 5; i++)
    {
        this->myHand.push_back(myDeck->drawCard());
    }
}

// Draw a new card
void Hand::drawNewCard(int cardPosition, Deck*& myDeck)
{
    this->myHand.at(cardPosition) = myDeck->drawCard();
}

void Hand::drawHand()
{
    cout << "+---------+ +---------+ +---------+ +---------+ +---------+" << endl;
    for(Card c : myHand)
    {
        if(c.getRank() != Card::rank_t::Ten)
            cout << "|" << c.getRankSymbol() << "        | ";
        else
            cout << "|" << c.getRankSymbol() << "       | ";
    }
    cout << endl;
    cout << "|         | |         | |         | |         | |         |" << endl;
    cout << "|         | |         | |         | |         | |         |" << endl;
    for(Card c : myHand)
    {
        cout << "|    " << c.getSuitSymbol() << "    | ";
    }
    cout << endl;
    cout << "|         | |         | |         | |         | |         |" << endl;
    cout << "|         | |         | |         | |         | |         |" << endl;
    for(Card c : myHand)
    {
        if(c.getRank() != Card::rank_t::Ten)
            cout << "|        " << c.getRankSymbol() << "| ";
        else
            cout << "|       " << c.getRankSymbol() << "| ";
    }
    cout << endl;
    cout << "+---------+ +---------+ +---------+ +---------+ +---------+" << endl;
}

// sort the hand; makes for easier calculations
void Hand::sortHand()
{
    std::sort(this->myHand.begin(), this->myHand.end());
}

void Hand::setHandResult(string handResult)
{
    this->handResult = handResult;
}

string Hand::getHandResult()
{
    return this->handResult;
}

// determine the payout of the hand; starts with highest payout multiplier first
int Hand::checkPayout()
{
    // sort the hand first; makes determining the hand contents easier
    this->sortHand();
    
    // Royal Flush - Cards are Ten through Ace of the same suit (payout 250x)
    if((myHand.at(0).getRank() == Card::rank_t::Ten && myHand.at(1).getRank() == Card::rank_t::Jack && myHand.at(2).getRank() == Card::rank_t::Queen && myHand.at(3).getRank() == Card::rank_t::King && myHand.at(4).getRank() == Card::rank_t::Ace) && (myHand.at(0).getSuit() == myHand.at(1).getSuit() && myHand.at(1).getSuit() == myHand.at(2).getSuit() && myHand.at(2).getSuit() == myHand.at(3).getSuit() && myHand.at(3).getSuit() == myHand.at(4).getSuit()))
    {
        this->setHandResult("Royal Flush");
        return 250;
    }

    // Straight Flush - Cards are sequential with the same suit (payout 50x)
    if(((int)myHand.at(0).getRank() + 1 == (int)myHand.at(1).getRank() && (int)myHand.at(1).getRank() + 1 == (int)myHand.at(2).getRank() && (int)myHand.at(2).getRank() + 1 == (int)myHand.at(3).getRank() && (int)myHand.at(3).getRank() + 1 == (int)myHand.at(4).getRank()) && (myHand.at(0).getSuit() == myHand.at(1).getSuit() && myHand.at(1).getSuit() == myHand.at(2).getSuit() && myHand.at(2).getSuit() == myHand.at(3).getSuit() && myHand.at(3).getSuit() == myHand.at(4).getSuit()))
    {
        this->setHandResult("Straight Flush");
        return 50;
    }

    // Four of a Kind - four cards of the same rank (payout 25x)
    if((myHand.at(0).getRank() == myHand.at(1).getRank() && myHand.at(1).getRank() == myHand.at(2).getRank() && myHand.at(2).getRank() == myHand.at(3).getRank() || (myHand.at(1).getRank() == myHand.at(2).getRank() && myHand.at(2).getRank() == myHand.at(3).getRank() && myHand.at(3).getRank() == myHand.at(4).getRank())))
    {
        this->setHandResult("Four of a Kind");
        return 25;
    }

    // Full House - three of a kind and a pair (payout 9x)
    if((myHand.at(0).getRank() == myHand.at(1).getRank() && myHand.at(1).getRank() == myHand.at(2).getRank() && myHand.at(3).getRank() == myHand.at(4).getRank()) || (myHand.at(2).getRank() == myHand.at(3).getRank() && myHand.at(3).getRank() == myHand.at(4).getRank() && myHand.at(0).getRank() == myHand.at(1).getRank()))
    {
        this->setHandResult("Full House");
        return 9;
    }

    // Flush - all cards are the same suit (payout 6x)
    if(myHand.at(0).getSuit() == myHand.at(1).getSuit() && myHand.at(1).getSuit() == myHand.at(2).getSuit() && myHand.at(2).getSuit() == myHand.at(3).getSuit() && myHand.at(3).getSuit() == myHand.at(4).getSuit())
    {
        this->setHandResult("Flush");
        return 6;
    }

    // Straight - all cards are sequential (payout 4x)
    if((int)myHand.at(0).getRank() + 1 == (int)myHand.at(1).getRank() && (int)myHand.at(1).getRank() + 1 == (int)myHand.at(2).getRank() && (int)myHand.at(2).getRank() + 1 == (int)myHand.at(3).getRank() && (int)myHand.at(3).getRank() + 1 == (int)myHand.at(4).getRank())
    {
        this->setHandResult("Straight");
        return 4;
    }

    // Three of a Kind - three cards are the same rank (payout 3x)
    if((myHand.at(0).getRank() == myHand.at(1).getRank() && myHand.at(1).getRank() == myHand.at(2).getRank()) || (myHand.at(1).getRank() == myHand.at(2).getRank() && myHand.at(2).getRank() == myHand.at(3).getRank()) || (myHand.at(2).getRank() == myHand.at(3).getRank() && myHand.at(3).getRank() == myHand.at(4).getRank()))
    {
        this->setHandResult("Three of a Kind");
        return 3;
    }

    // Two Pair - two cards are the same rank, and two separate cards are the same distinct rank (payout 2x)
    if((myHand.at(0).getRank() == myHand.at(1).getRank() && myHand.at(2).getRank() == myHand.at(3).getRank()) || (myHand.at(0).getRank() == myHand.at(1).getRank() && myHand.at(3).getRank() == myHand.at(4).getRank()) || (myHand.at(1).getRank() == myHand.at(2).getRank() && myHand.at(3).getRank() == myHand.at(4).getRank()))
    {
        this->setHandResult("Two Pair");
        return 2;
    }

    // Pair of Jacks or better - two cards are the same rank and better than Jacks (payout 1x)
    if((myHand.at(0).getRank() == myHand.at(1).getRank() && (int)myHand.at(0).getRank() > 10) || (myHand.at(1).getRank() == myHand.at(2).getRank() && (int)myHand.at(1).getRank() > 10) || (myHand.at(2).getRank() == myHand.at(3).getRank() && (int)myHand.at(2).getRank() > 10) || (myHand.at(3).getRank() == myHand.at(4).getRank() && (int)myHand.at(3).getRank() > 10))
    {
        this->setHandResult("Pair of Jacks or Better");
        return 1;
    }

    // if we find no match, you get nothing, good day sir!
    this->setHandResult("Nothing");
    return 0;
}