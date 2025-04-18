
#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <vector>
using namespace std;

class Deck {
private:
vector<Card> m_cardDeck;
    void shuffleDeck();

    public:
    Deck();
    Card dealCard();
    int getCount();
};



#endif //DECK_H
