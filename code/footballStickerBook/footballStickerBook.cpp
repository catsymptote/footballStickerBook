// footballStickerBook.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <cstdlib>
#include <time.h>
#include <iostream>


std::vector<int> cardBook;
const int bookSize = 682 + 1;
const int bagSize = 5;


void makeCardBook()
{
	for(int i = 0; i < bookSize; i++)
		cardBook.push_back(i);
}

int randomNumber()
{
	return (rand() % (bookSize - 0));
}

std::vector<int> randomCards()
{
	std::vector<int> newCards;
	for (int i = 0; i < bagSize; i++)
		newCards.push_back(randomNumber());
	return newCards;
}

void cardsInBook(std::vector<int> newCards)
{
	int i = 0, j;
	while (i < cardBook.size() - 1)
	{
		j = 0;
		while (j < newCards.size())
		{
			if (cardBook.at(i) == newCards.at(j))
			{
				cardBook.erase(cardBook.begin() + i);
			}
			j++;
		}
		i++;
	}
}


int main()
{
	
	srand(time(NULL));
	const int totalRuns = 10;
	int results[totalRuns];
	
	for (int i = 0; i < totalRuns; i++)
	{
		makeCardBook();
		int cardBags = 0;
		while (cardBook.size() > 1)
		{
			//std::cout << cardBook.size() << "\t" << cardBags << std::endl;
			cardsInBook(randomCards());
			cardBags++;
		}
		results[i] = cardBags;
		std::cout << ".";
	}

	int average = 0;
	/// Average
	for (int i = 0; i < totalRuns; i++)
	{
		average += results[i];
	}
	average /= totalRuns;

	std::cout << "\n\nAverage runs: " << average
		<< " based on " << totalRuns << " runs." << std::endl;

	/*
	std::cout << "It took " << cardBags
		<< " bags of cards to fill the book." << std::endl;

	std::cout << "That is " << cardBags*5
		<< " cards, " << cardBags*5 - bookSize
		<< " of which were discarded." << std::endl;
	*/

    return 0;
}
