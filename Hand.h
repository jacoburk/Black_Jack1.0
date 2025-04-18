#ifndef HAND_H
#define HAND_H
#include <vector>
#include "Card.h"

class Hand {
private:
    vector<Card> m_hand;

public:
    Hand();
    void clearHand();
    void operator+=(Card);
    Card displayCard(int);
    int getPoints();
    int cardCount();
};

#endif //HAND_H
