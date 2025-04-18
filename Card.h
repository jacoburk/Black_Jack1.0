
#ifndef CARD_H
#define CARD_H
#include<string>
using namespace std;


class Card {
private:
    string m_suit;
    string m_rank;
    int m_value;

    public:
    Card();
    Card(string suit, string rank, int value);
    string getRank();
    int getValue();
    string getCard();
};



#endif //CARD_H
