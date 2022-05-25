#pragma once
#include<iostream>

class PlayerChoice
{
private:
	char m_choice{};
	void printEnterChoice() const 
	{
		std::cout << "(h) to hit, or (s) to stand: ";
	}
public:
	void setChoice() {
		printEnterChoice();
		do
		{
			std::cin >> m_choice;
		} while (m_choice != 'h' && m_choice != 's');
	}
	char getChoice() const {
		return m_choice;
	}
	PlayerChoice() {
		setChoice();
	}
};

