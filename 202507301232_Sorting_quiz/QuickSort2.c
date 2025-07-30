#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Score.h"

int ComparePoint(const void* _elem1, const void* _elem2)
{
	const Score* elem1 = (const Score*)_elem1;
	const Score* elem2 = (const Score*)_elem2;

	if (elem1->score > elem2->score)
		return 1;
	else if (elem1->score < elem2->score)
		return -1;
	else
		return 0;
}


int main(void)
{
	int Length = sizeof(DataSet) / sizeof(DataSet[0]);
	int i = 0;

	qsort((void*)DataSet, Length, sizeof(Score), ComparePoint);

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
