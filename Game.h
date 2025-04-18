
#ifndef GAME_H
#define GAME_H
#include "Hand.h"
#include "Deck.h"
#include <iostream>
using namespace std;


class Game {
private:
    Hand m_dealerHand;
    Deck m_deck;
    Hand m_playerHand;
public:
    Game();
    Hand getPlayerHand(Deck &deck, Hand &hand);
    Hand getDealerHand(Deck &deck, Hand &hand);
    void displayCards (Hand hand, string name);
    void displayRound();
    void playGame();
};



#endif //GAME_H
