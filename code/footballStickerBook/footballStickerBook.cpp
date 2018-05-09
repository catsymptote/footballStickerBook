// footballStickerBook.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <cstdlib>
#include <iostream>


std::vector<int> cardBook;
int bookSize = 582;
int bagSize = 5;

void makeCardBook()
{
	for(int i = 0; i < bookSize; i++)
		cardBook.push_back(i);
}

int randomNumber()
{
	return (rand() % bookSize);
}

std::vector<int> randomCards()
{
	std::vector<int> newCards;
	for (int i = 0; i < bagSize; i++)
		cardBook.push_back(randomNumber());
	return newCards;
}

void cardsInBook(std::vector<int> newCards)
{
	int i = 0, j = 0;
	while (i < cardBook.size())
	{
		while (j < newCards.size())
		{
			if (cardBook.at(i) == newCards.at(j))
				cardBook.erase(cardBook.begin() + i);
			j++;
		}
		i++;
	}
}


int main()
{
	int cardBags = 0;
	makeCardBook();
	while (cardBook.size() > 0)
	{
		cardsInBook(randomCards());
		cardBags++;
		if(cardBags % 1000 == 0)
			std::cout << cardBags << std::endl;
	}

	std::cout << "It took " << cardBags << " bags of cards to fill the book." << std::endl;
	std::cout << "That is " << cardBags*5 << " cards, " << cardBags*5 - bookSize << " of which were discarded." << std::endl;

    return 0;
}

