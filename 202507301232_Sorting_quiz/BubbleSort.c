/*
#include <stdio.h> 
#include "Score.h"
#include <time.h>

void BubbleSort(Score DataSet[], int Length)
{
    int i = 0;
    int j = 0;
    Score temp;

    for (i = 0; i < Length - 1; i++)
    {
        for (j = 0; j < Length - (i + 1); j++)
        {
            if (DataSet[j].score > DataSet[j + 1].score)
            {
                temp = DataSet[j + 1];
                DataSet[j + 1] = DataSet[j];
                DataSet[j] = temp;
            }
        }
    }
}

// 문제
// score.h 파일에 저장된 3만개의 데이타를 score 순으로 정렬해서 앞에 1 ~ 10개 뒤에 29990 ~ 29999개를 출력해보세요.
// 버블소트
// 삽입정렬
// 퀵소트
// 퀵소트2


int main(void)
{
    //int DataSet[] = {6, 4, 2, 3, 1, 5}; 
    int Length = sizeof DataSet / sizeof DataSet[0];
    int i = 0;

    double startTime = 0.0, endTime = 0.0;
    startTime = (double)clock() / CLOCKS_PER_SEC;

    BubbleSort(DataSet, Length);
    endTime = (double)clock() / CLOCKS_PER_SEC;

    printf("1~10개: \n");
    for (i = 0; i < 10; i++)
    {
        printf("번호: %d, 점수: %f\n", DataSet[i].number, DataSet[i].score);
    }

    printf("------------------------------------------------------\n");

    printf("\n29990~29999개: \n");
    for (i = 29990; i <= 29999; i++)
    {
        printf("번호: %d, 점수: %f\n", DataSet[i].number, DataSet[i].score);
    }

    printf("\n");
    printf("버블소트 3만개 데이터 소팅 시간: %lf sec\n", endTime - startTime);


    return 0;
}
*/