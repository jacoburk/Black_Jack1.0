#include "Game.h"

Game :: Game() {
    playGame();

}
Hand Game :: getPlayerHand(Deck &deck, Hand &hand) {
    hand += deck.dealCard();
    hand += deck.dealCard();
    return hand;
}
Hand Game :: getDealerHand(Deck &deck, Hand &hand) {
    hand += deck.dealCard();
    hand += deck.dealCard();
    return hand;
}
void Game :: displayCards (Hand hand, string name) {
    if (name == "Dealer") {
        cout << "Dealer's Cards:" << endl;
    } else {
        cout << name <<" Cards: " << endl;
    }
    for (int i = 0; i < hand.cardCount(); i++) {
        cout << hand.displayCard(i).getCard() << endl;
    }
    cout << endl;
}
void Game :: displayRound() {
    cout << "Dealer's Show Card: "<<endl;
    cout << m_dealerHand.displayCard(0).getCard() << endl<<endl;
    displayCards(m_playerHand, "Your");

}

void Game :: playGame() {
   cout << "###########################" << endl;
    cout << "#  The Game of Blackjack  #" << endl;
    cout << "###########################" << endl;
    cout <<  endl;

    char playAgain = 'y';
    while (playAgain == 'y' || playAgain == 'Y') {
        m_deck = Deck();
        m_playerHand.clearHand();
        m_dealerHand.clearHand();

        m_playerHand = getPlayerHand(m_deck, m_playerHand);
        m_dealerHand = getDealerHand(m_deck, m_dealerHand);

        displayRound();

        char choice;
        do {
            cout << "hit or stand? (h/s): ";
            cin >> choice;
            if (choice == 'h' || choice == 'H') {
                m_playerHand += m_deck.dealCard();
                cout << endl<<"Your Cards: "<<endl;
                for (int i = 0; i < m_playerHand.cardCount(); i++) {
                    cout << m_playerHand.displayCard(i).getCard() << endl;
                }
                cout << endl;
            }

        }while ((choice == 'h' || choice == 'H') and m_playerHand.getPoints() <21);

        if (m_playerHand.getPoints() <= 21) {
            while (m_dealerHand.getPoints() < 17) {
                m_dealerHand += m_deck.dealCard();
            }
        }

        displayCards(m_dealerHand, "Dealer");
        cout << endl;

        cout << "Your Points:     " << m_playerHand.getPoints() << endl;
        cout << "Dealer's Points: " << m_dealerHand.getPoints() << endl;


        int playerPoints = m_playerHand.getPoints();
        int dealerPoints = m_dealerHand.getPoints();


        if (playerPoints > 21) {
            cout << "Sorry. You busted. You lose."<<endl;
        }else if (dealerPoints > 21) {
            cout << "Yay! The dealer busted. You win!"<<endl;
        }else if (playerPoints < dealerPoints && dealerPoints ==21 ) {
            cout <<"Dealer has Blackjack. You lose."<<endl;
        }else if (playerPoints > dealerPoints && playerPoints ==21 ) {
            cout <<"Blackjack! You win!"<<endl;
        }else if (playerPoints == dealerPoints && playerPoints ==21 ) {
            cout <<"Dang, dealer has blackjack too. You push."<<endl;
        } else if (playerPoints > dealerPoints) {
            cout << "Hooray! You win!"<<endl;
        } else if (playerPoints < dealerPoints) {
            cout << "Sorry. You lose."<<endl;
        }
        else if(playerPoints == dealerPoints) {
            cout << "It's a tie!, you push"<<endl;
        }else {
            cout<< "I'm not sure what happened."<<endl;
        }
        cout << "play another round? (y/n) : " ;
        cin >> playAgain;
        cout << endl;
    }

    cout << "Thanks for playing!" << endl;
}