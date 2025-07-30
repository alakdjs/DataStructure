/*
#include <stdio.h>
#include "Score.h"

void Swap(Score* A, Score* B)
{
	Score Temp = *A;
	*A = *B;
	*B = Temp;
}

int Partition(Score DataSet[], int Left, int Right)
{
	int First = Left;
	double Pivot = DataSet[First].score;

	++Left;
	while (Left <= Right)
	{
		while (DataSet[Left].score <= Pivot && Left < Right)
			++Left;
		while (DataSet[Right].score >= Pivot && Left <= Right)
			--Right;

		if (Left < Right)
			Swap(&DataSet[Left], &DataSet[Right]);
		else
			break;
	}

	Swap(&DataSet[First], &DataSet[Right]);

	return Right;
}

void QuickSort(Score DataSet[], int Left, int Right)
{
	if (Left < Right)
	{
		int Index = Partition(DataSet, Left, Right);

		QuickSort(DataSet, Left, Index - 1);
		QuickSort(DataSet, Index + 1, Right);
	}
}

int main(void)
{
	int Length = sizeof(DataSet) / sizeof(DataSet[0]);
	int i = 0;

	QuickSort(DataSet, 0, Length - 1);

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