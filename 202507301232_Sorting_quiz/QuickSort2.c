#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Score.h"
#include <time.h>

//  리턴값이 
//  < 0 이면, _elem1이 _elem2보다 작다. 
//  = 0   이면, _elem1이 _elem2와 같다.  
//  > 0 이면, _elem1이 _elem2보다 크다.
int ComparePoint(const void* _elem1, const void* _elem2)
{
	Score* elem1 = (Score*)_elem1;
	Score* elem2 = (Score*)_elem2;

	if ((*elem1).score > (*elem2).score) // = (elem1->score > elem2->score)
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
	
	double startTime = 0.0, endTime = 0.0;
	startTime = (double)clock() / CLOCKS_PER_SEC;

	qsort((void*)DataSet, Length, sizeof(Score), ComparePoint);

	endTime = (double)clock() / CLOCKS_PER_SEC;

	printf("1~10개: \n");
	for (i = 0; i < 10; i++)
	{
		printf("번호: %d, 점수: %f\n", DataSet[i].number, DataSet[i].score);
	}

	printf("------------------------------------------------------\n");

	printf("\n29990~29999개: \n");
	for (i = 29990; i <= 29999; i++) // = for (i = Length - 10; i < Length; i++)
	{
		printf("번호: %d, 점수: %f\n", DataSet[i].number, DataSet[i].score);
	}
	printf("\n");
	printf("퀵정렬2.. 3만개 데이터 소팅 시간: %lf sec\n", endTime - startTime);

	return 0;
}
