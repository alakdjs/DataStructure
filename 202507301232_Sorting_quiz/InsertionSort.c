/*
#include <stdio.h>
#include <string.h>
#include "Score.h"

void InsertionSort(Score DataSet[], int Length)
{
	int i = 0;
	int j = 0;
	Score value;

	for (i = 1; i < Length; i++)
	{
		if (DataSet[i - 1].score <= DataSet[i].score)
		{
			continue;
		}

		value = DataSet[i];

		for (j = 0; j < i; j++)
		{
			if (DataSet[j].score > value.score)
			{
				memmove(&DataSet[j + 1], &DataSet[j], sizeof(Score) * (i - j));
				DataSet[j] = value;
				break;
			}
		}
	}
}

int main(void) {
	int Length = sizeof(DataSet) / sizeof(DataSet[0]);
	int i = 0;

	InsertionSort(DataSet, Length);
	
	printf("1~10개: \n");
    for (i = 0; i < 10; i++)
    {
        printf("번호: %d, 점수: %f\n", DataSet[i].number, DataSet[i].score);
    }

    printf("\n29990~29999개: \n");
    for (i = 29990; i <= 29999; i++)
    {
        printf("번호: %d, 점수: %f\n", DataSet[i].number, DataSet[i].score);
    }
	printf("\n");

	return 0;
}
*/