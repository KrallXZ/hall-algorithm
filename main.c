#include <stdio.h>
#include "osoby.h"

enum osoby pary[LICZBA_OSOB];
int propozycje[LICZBA_MEZCZYZN];

int ocena(int mezczyzna, int kobieta)
{
	unsigned int ocena = 0;

	do
	{
		ocena++;
	} while (ocena <= LICZBA_MEZCZYZN && preferencje[mezczyzna][ocena] != kobieta);

	return ocena;
}

void pokazPary()
{
	printf("Uzyskane pary to:\n");
	for (int i = 0; i < LICZBA_MEZCZYZN; i++)
	{
		if (pary[i] == -1)
		{
			printf("\t%s nie ma pary. :(\n", imiona[i]);
			continue;
		}

		printf("\t%s ♥ %s\n", imiona[i], imiona[pary[i]]);
	}
}

void znajdzPare(enum osoby mezczyzna, enum osoby kobieta)
{
	int paraKobiety = pary[kobieta];

	if (paraKobiety == -1)
	{
		pary[mezczyzna] = kobieta;
		pary[kobieta] = mezczyzna;
	}
	else if (ocena(kobieta, mezczyzna) < ocena(kobieta, paraKobiety))
	{
		pary[paraKobiety] = -1;
		pary[mezczyzna] = kobieta;
		pary[kobieta] = mezczyzna;
	}
}

int main()
{
	system("chcp 65001");
	system("cls");
	for (int i = 0; i <= LICZBA_OSOB; i++)
	{
		pary[i] = -1;
		propozycje[i] = -1;
	}

	int szukajDalej;
	do
	{
		szukajDalej = 0;
		for (int i = 0; i <= LICZBA_MEZCZYZN; i++)
		{
			if (pary[i] != -1)
				continue;
			
			propozycje[i] += 1;
			
			if (propozycje[i] < LICZBA_KOBIET) {
				znajdzPare(i, preferencje[i][propozycje[i]]);
				szukajDalej = 1;
			}
		}
	} while (szukajDalej);

	pokazPary();

	return 0;
}
