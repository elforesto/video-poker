#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int main()
{
    Deck* myDeck = new Deck(); // create a deck
    float balance = 100.00; // starting balance
    int bet = 0; // hand bet
    int winnings; // winnings multiplier
    string cardsHeld; // list of cards to hold
    float betAmount = 0.00;
    bool keepPlaying = true;
    char continuePlaying;
    cout << "Welcome to Video Poker! Your balance is $" << std::fixed << std::setprecision(2) << balance << endl;

    while(keepPlaying)
    {
        system("clear"); // clear the screen
        cout << "Your balance is $" << std::fixed << std::setprecision(2) << balance << endl;
        cout << "Please pick your bet:\t$1.00\t$0.25\t$0.05" << endl;
        cout << "\t\t\t1\t2\t3" << endl;
        cin >> bet;
        switch(bet)
        {
            case 1:
                betAmount = 1.00;
                break;
            case 2:
                betAmount = 0.25;
                break;
            case 3:
                betAmount = 0.05;
                break;
        }
        balance -= betAmount;
        Hand* myHand = new Hand(myDeck); // create a hand
        system("clear");
        cout << "Bet Amount: $" << std::fixed << std::setprecision(2) << betAmount << "\tBalance: $" << std::fixed << std::setprecision(2) << balance << endl;
        myHand->sortHand(); // sort the hand for easy display/calculation
        myHand->drawHand(); // draw the cards on the screen
        cout << "Choose which cards to discard (1, 2, 3, 4, 5) or H to hold and press Enter: ";
        cin >> cardsHeld;
        for(char& c : cardsHeld)
        {
            if(c == 'H' || c == 'h')
                break;
            myHand->drawNewCard(((int)c - (int)('0') - 1), myDeck);
        }
        system("clear");
        cout << "Bet Amount: $" << std::fixed << std::setprecision(2) << betAmount << "\tBalance: $" << std::fixed << std::setprecision(2) << balance << endl;
        myHand->sortHand();
        myHand->drawHand();
        winnings = myHand->checkPayout();
        cout << "Your hand result: " << myHand->getHandResult() << endl;
        if(winnings > 0)
        {
            balance += (winnings * betAmount);
            cout << "Your hand paid out $" << std::setprecision(2) << (winnings * betAmount) << endl;
        } else {
            cout << "You lost this hand! Better luck next time." << endl;
        }
        cout << "Your current wallet balance is $" << std::setprecision(2) << balance << endl;
        delete myHand; // delete the hand; we'll make a new one each round
        myDeck->shuffleDeck(); // shuffle the deck
        if(balance <= 0)
        {
            keepPlaying = false;
            cout << "You're broke! Like they say, the house always wins." << endl;
            break;
        } else {
            cout << "Would you like to keep playing? (y/n): ";
            cin >> continuePlaying;
            switch(continuePlaying)
            {
                case 'y':
                    keepPlaying = true;
                    break;
                case 'Y':
                    keepPlaying = true;
                    break;
                case 'n':
                    keepPlaying = false;
                    break;
                case 'N':
                    keepPlaying = false;
                    break;
                default:
                    cout << "Since you can't follow directions, we'll just keep on playing anyway. Dork." << endl;
                    keepPlaying = true;
                    break;
            }
        }
 
    }

    return 0;
}