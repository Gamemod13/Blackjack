#pragma once
#include<array>
#include"Card.h"
#include<assert.h>
class Deck
{
private:

	std::array<Card, 52> m_deck;
	unsigned int m_cardIndex{ 0 };

	static int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); // используем static, так как это значение нужно вычислить единожды
		// Равномерно распределяем вычисление значения из нашего диапазона
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}

	static void swapCard(Card& a, Card& b)
	{
		Card temp = a;
		a = b;
		b = temp;
	}
public:
	Deck() {
		int card = 0;
		for (int suit = 0; suit < Card::MAX_SUITS; ++suit) {
			for (int rank = 0; rank < Card::MAX_RANKS; ++rank)
			{
				m_deck[card] = Card(static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit));
				++card;
			}
		}
	}
	void printDeck() const {
		for (const auto& card : m_deck)
		{
			card.printCard();
			std::cout << ' ';
		}

		std::cout << '\n';
	}
	void shuffleDeck()
	{
		// Перебираем каждую карту в колоде
		for (int index = 0; index < 52; ++index)
		{
			// Выбираем любую случайную карту
			int swapIndex = getRandomNumber(0, 51);
			// Меняем местами с нашей текущей картой
			swapCard(m_deck[index], m_deck[swapIndex]);
		}
		m_cardIndex = 0;
	}
	const Card& dealCard() {
		assert(m_cardIndex < 52);
		return m_deck[m_cardIndex++];
	}
	const Card& getFirstCard() const {
		return m_deck[0];
	}
};