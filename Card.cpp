#include "Card.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

// Constructor - calls setters for suit and rank
Card::Card(Card::suit_t suit, Card::rank_t rank)
{
    this->cardSuit = suit;
    this->cardRank = rank;
}

// allows using int values for suits and ranks and recasts them as the appropriate enum
Card::Card(int suit, int rank)
{
    //doesn't work; needs corrected delegating constructor
    //Card(static_cast<suit_t>(suit), static_cast<rank_t>(rank));
    this->cardSuit = static_cast<suit_t>(suit);
    this->cardRank = static_cast<rank_t>(rank);
}

// sets suit
void Card::setSuit(Card::suit_t suit)
{
    this->cardSuit = suit;
}

// sets rank
void Card::setRank(Card::rank_t rank)
{
    this->cardRank = rank;
}

// suit functions
// return the suit enum
Card::suit_t Card::getSuit()
{
    return this->cardSuit;
}

// get suit name as a string
string Card::getSuitName()
{
    switch(Card::getSuit()) {
        case suit_t::Clubs:
            return "Clubs";
        case suit_t::Diamonds:
            return "Diamonds";
        case suit_t::Hearts:
            return "Hearts";
        case suit_t::Spades:
            return "Spades";
        default:
            return "INVALID SUIT";
    }
}

// get suit as a symbol for printing the card
string Card::getSuitSymbol()
{
    switch(Card::getSuit()) {
        case suit_t::Clubs:
            return "♣";
        case suit_t::Diamonds:
            return "♦";
        case suit_t::Hearts:
            return "♥";
        case suit_t::Spades:
            return "♠";
        default:
            return "INVALID SUIT";
    }
}

// rank functions
// return the rank enum
Card::rank_t Card::getRank()
{
    return this->cardRank;
}

// get rank name as a string
string Card::getRankName()
{
    switch(Card::getRank()) {
        case rank_t::Two:
            return "Two";
        case rank_t::Three:
            return "Three";
        case rank_t::Four:
            return "Four";
        case rank_t::Five:
            return "Five";
        case rank_t::Six:
            return "Six";
        case rank_t::Seven:
            return "Seven";
        case rank_t::Eight:
            return "Eight";
        case rank_t::Nine:
            return "Nine";
        case rank_t::Ten:
            return "Ten";
        case rank_t::Jack:
            return "Jack";
        case rank_t::Queen:
            return "Queen";
        case rank_t::King:
            return "King";
        case rank_t::Ace:
            return "Ace";
        default:
            return "INVALID RANK";
    }
}

// get rank as a symbol for printing the card
string Card::getRankSymbol()
{
    switch(Card::getRank()) {
        case rank_t::Two:
            return "2";
        case rank_t::Three:
            return "3";
        case rank_t::Four:
            return "4";
        case rank_t::Five:
            return "5";
        case rank_t::Six:
            return "6";
        case rank_t::Seven:
            return "7";
        case rank_t::Eight:
            return "8";
        case rank_t::Nine:
            return "9";
        case rank_t::Ten:
            return "10";
        case rank_t::Jack:
            return "J";
        case rank_t::Queen:
            return "Q";
        case rank_t::King:
            return "K";
        case rank_t::Ace:
            return "A";
        default:
            return "INVALID RANK";
    }

}

// text-based card graphics - for testing/validation
void Card::drawCard()
{
    cout << "+---------+" << endl;
    if(Card::getRank() != rank_t::Ten)
        cout << "|" << Card::getRankSymbol() << "        |" << endl;
    else
        cout << "|" << Card::getRankSymbol() << "       |" << endl;
    cout << "|         |" << endl;
    cout << "|         |" << endl;
    cout << "|    " << Card::getSuitSymbol() << "    |" << endl;
    cout << "|         |" << endl;
    cout << "|         |" << endl;
    if(Card::getRank() != rank_t::Ten)
        cout << "|        " << Card::getRankSymbol() << "|" << endl;
    else
        cout << "|       " << Card::getRankSymbol() << "|" << endl;
    cout << "+---------+" << endl;
}

// test output to validate translating enum to string
void Card::printCard()
{
    cout << "Card is " << Card::getRankName() << " of " << Card::getSuitName() << endl ;
}

bool operator<(Card& c1, Card& c2)
{
    return (int)c1.getRank() < (int)c2.getRank();
}

bool operator>(Card& c1, Card& c2)
{
    return !((int)c1.getRank() < (int)c2.getRank());
}