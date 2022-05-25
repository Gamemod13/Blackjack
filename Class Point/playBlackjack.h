#pragma once
#include"Deck.h"
class playBlackjack
{
private:
	const Card* m_cardPtr{};
	int m_playerTotal{0};
	int m_dealerTotal{0};
public:
	 playBlackjack(Deck &deck)
		: m_cardPtr(&deck.getFirstCard())
	{
	}
	 void GetCards() {
		 m_dealerTotal += m_cardPtr++->getCardValue();
		 
		 std::cout << "The dealer now has: " << m_dealerTotal << std::endl;
		 m_playerTotal += m_cardPtr++->getCardValue();
		 m_playerTotal += m_cardPtr++->getCardValue();
	 }
};

