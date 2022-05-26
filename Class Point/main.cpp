#include <iostream>
#include <ctime> // дл€ time()
#include <cstdlib> // дл€ rand() и srand()
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

	// ƒилер получает одну карту
	dealerTotal += cardPtr++->getCardValue();
	std::cout << "The dealer is showing: " << dealerTotal << '\n';

	// »грок получает две карты
	playerTotal += cardPtr++->getCardValue();
	playerTotal += cardPtr++->getCardValue();

	// »грок начинает
	while (1)
	{
		std::cout << "You have: " << playerTotal << '\n';
		char choice = getPlayerChoice();
		if (choice == 's')
			break;

		playerTotal += cardPtr++->getCardValue();

		// —мотрим, не проиграл ли игрок
		if (playerTotal > 21) {
			std::cout << "You have: " << playerTotal << '\n';
			return false;
		}
	}

	// ≈сли игрок не проиграл (у него не больше 21 очка), тогда дилер получает карты до тех пор, пока у него в сумме будет не меньше 17 очков
	while (dealerTotal < 17)
	{
		dealerTotal += cardPtr++->getCardValue();
		std::cout << "The dealer now has: " << dealerTotal << '\n';
	}

	// ≈сли у дилера больше 21, то он проиграл, а игрок выиграл
	if (dealerTotal > 21)
		return true;

	return (playerTotal > dealerTotal);
}


int main()
{
	srand(static_cast<unsigned int>(time(0))); // используем системные часы в качестве стартового значени€
	rand(); // пользовател€м Visual Studio: делаем сброс первого случайного числа

	Deck deck;
	//deck.printDeck();
    deck.shuffleDeck();

	if (playBlackjack(deck))
		std::cout << "You win!\n";
	else
		std::cout << "You lose!\n";

	return 0;
}