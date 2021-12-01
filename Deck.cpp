#include "Card.h"
#include "Deck.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

// Default constructor
Deck::Deck()
{
    for(int i = 1; i < 5; i++)
    {
        for(int j = 2; j < 15; j++)
        {
            myDeck.push_back(Card(i, j));
        }
    }
    this->shuffleDeck();
    this->topCard = 0;
};

// Draw the card from the top of the deck
Card Deck::drawCard()
{
    return myDeck.at(this->topCard++);
}

// return the number of cards in the deck
int Deck::getDeckSize()
{
    return myDeck.size();
}

// Shuffle the deck
void Deck::shuffleDeck()
{
    std::random_device rd;
    auto rng = std::default_random_engine { rd() };
    std::shuffle(std::begin(myDeck), std::end(myDeck), rng);
    this->topCard = 0;
}