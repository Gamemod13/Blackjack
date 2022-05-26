#include <iostream>
#include <ctime> // ��� time()
#include <cstdlib> // ��� rand() � srand()
#include"Card.h"
#include"Deck.h"


char getPlayerChoice()
{
	std::cout << "(h) to hit, or (s) to stand: ";
	char choice{};
	do
	{
		std::cin >> choice;
	} while (choice != 'h' && choice != 's');

	return choice;
}
bool playBlackjack(Deck &deck)
{
	const Card* cardPtr = &deck.getFirstCard();

	int playerTotal = 0;
	int dealerTotal = 0;

	// ����� �������� ���� �����
	dealerTotal += cardPtr++->getCardValue();
	std::cout << "The dealer is showing: " << dealerTotal << '\n';

	// ����� �������� ��� �����
	playerTotal += cardPtr++->getCardValue();
	playerTotal += cardPtr++->getCardValue();

	// ����� ��������
	while (1)
	{
		std::cout << "You have: " << playerTotal << '\n';
		char choice = getPlayerChoice();
		if (choice == 's')
			break;

		playerTotal += cardPtr++->getCardValue();

		// �������, �� �������� �� �����
		if (playerTotal > 21) {
			std::cout << "You have: " << playerTotal << '\n';
			return false;
		}
	}

	// ���� ����� �� �������� (� ���� �� ������ 21 ����), ����� ����� �������� ����� �� ��� ���, ���� � ���� � ����� ����� �� ������ 17 �����
	while (dealerTotal < 17)
	{
		dealerTotal += cardPtr++->getCardValue();
		std::cout << "The dealer now has: " << dealerTotal << '\n';
	}

	// ���� � ������ ������ 21, �� �� ��������, � ����� �������
	if (dealerTotal > 21)
		return true;

	return (playerTotal > dealerTotal);
}


int main()
{
	srand(static_cast<unsigned int>(time(0))); // ���������� ��������� ���� � �������� ���������� ��������
	rand(); // ������������� Visual Studio: ������ ����� ������� ���������� �����

	Deck deck;
	//deck.printDeck();
    deck.shuffleDeck();

	if (playBlackjack(deck))
		std::cout << "You win!\n";
	else
		std::cout << "You lose!\n";

	return 0;
}