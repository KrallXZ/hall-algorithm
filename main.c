#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "menu.h"
#include "persons.h"

int getPairRating(Person *lady, Person *gentleman)
{
	unsigned int rating = 0;

	do
	{
		rating++;
	} while (rating <= MAX && (lady->preferences[rating] != gentleman->id));

	return rating;
}

void printPairs(Persons *ladies, Persons *gentlemans, unsigned int *ladiesPairs)
{
	printf("Uzyskane pary to:\n");
	for (int i = 0; i < ladies->count; i++)
	{
		if (ladiesPairs[i] == -1)
		{
			printf("\t%s nie ma pary. 💔\n", ladies->array[i]->name);
			continue;
		}

		printf("\t%s 💕 %s\n", ladies->array[i]->name, gentlemans->array[ladiesPairs[i]]->name);
	}
}

void findPair(Person *lady, Person *gentleman, unsigned int *ladiesPairs, unsigned int *gentlemansPairs, Persons *ladies)
{
	unsigned int gentlemanPair = gentlemansPairs[gentleman->id];

	if (gentlemanPair == -1)
	{
		ladiesPairs[lady->id] = gentleman->id;
		gentlemansPairs[gentleman->id] = lady->id;
	}
	else if (getPairRating(lady, gentleman) < getPairRating(ladies->array[gentlemanPair], lady))
	{
		ladiesPairs[gentlemanPair] = -1;
		ladiesPairs[lady->id] = gentleman->id;
		gentlemansPairs[gentleman->id] = lady->id;
	}
}

void makePairs(Persons *ladies, Persons *gentlemans)
{
	unsigned int *ladiesPairs = malloc(sizeof(unsigned int) * ladies->count);
	unsigned int *ladiesPropositions = malloc(sizeof(unsigned int) * ladies->count);
	unsigned int *gentlemansPairs = malloc(sizeof(unsigned int) * gentlemans->count);

	for (int i = 0; i <= ladies->count; i++)
	{
		ladiesPairs[i] = -1;
		ladiesPropositions[i] = 0;
	}

	for (int i = 0; i <= gentlemans->count; i++)
	{
		gentlemansPairs[i] = -1;
	}

	bool done;

	do
	{
		done = true;
		for (int i = 0; i < ladies->count; i++)
		{
			if (ladiesPairs[i] != -1)
			{
				continue;
			}

			if (ladiesPropositions[i] < ladies->array[i]->preferencesCount)
			{
				findPair(ladies->array[i], gentlemans->array[ladies->array[i]->preferences[ladiesPropositions[i]]], ladiesPairs, gentlemansPairs, ladies);
				ladiesPropositions[i] += 1;
				done = false;
			}
		}
	} while (!done);

	printf("Jak chcesz wyświetlić pary?");
	unsigned int choice = showPrintMenu();
	switch (choice)
	{
	case 1:
		printPairs(ladies, gentlemans, ladiesPairs);
		break;
	case 2:
		printPairs(gentlemans, ladies, gentlemansPairs);
		break;
	case 0:
		return;
	}
	showBackMenu();
}

int main()
{
#ifdef _WIN32
	system("chcp 65001");
	system("cls");
#endif

	Persons *ladies = createPersons();
	Persons *gentlemans = createPersons();

	while (true)
	{
#ifdef _WIN32
		system("cls");
#else
		system("clear");
#endif
		printf("-=Love Maker 3000 💞=-\n");
		printf("W bazie jest aktualnie 👩 %d/%d kobiet oraz 👨 %d/%d mężczyzn.\n", ladies->count, MAX, gentlemans->count, MAX);
		unsigned int choice = showMainMenu();
		switch (choice)
		{
		case 1:
			printf("👩 Lista kobiet:\n");
			printPersons(ladies, gentlemans);
			break;
		case 2:
			printf("👨 Lista mężczyzn:\n");
			printPersons(gentlemans, ladies);
			break;
		case 3:
			makePairs(ladies, gentlemans);
			break;
		case 0:
			printf("Dziękujemy za skorzystanie z programu! 😍\n");
			return 0;
		}
	}

	return 0;
}
