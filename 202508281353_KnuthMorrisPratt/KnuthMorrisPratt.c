#include "KnuthMorrisPratt.h"
#include <stdlib.h>

void Preprocess(char* Pattern, int PatternSize, int* Border)
{
	int i = 0;
	int j = -1;

	Border[0] = -1;

	while (i < PatternSize)
	{
		while (j > -1 && Pattern[i] != Pattern[j])
			j = Border[j];

		i++;
		j++;

		Border[i] = j;
	}
}

int KnuthMorrisPratt(char* Text, int TextSize, int Start, char* Pattern, int PatternSize)
{
	int i = Start;
	int j = 0;

	int Position = -1;

	int* Border = (int*)calloc(PatternSize + 1, sizeof(int)); // ������̺� ����

	Preprocess(Pattern, PatternSize, Border); // ��� ���̺� ���� ����

	// BAABACABAABABAAB (����)
	// BAABABAA			(����)

	// i : 0
	// j : 0
	while (i < TextSize)	// TextSize: 16
	{
		while (j >= 0 && Text[i] != Pattern[j])
			j = Border[j];

		i++;
		j++;

		if (j == PatternSize)	// patternsize : 8
		{
			Position = i - j;
			break;
		}
	}

	free(Border);
	return Position;
}