/*
#include <stdio.h> 
#include "Score.h"

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

// ����
// score.h ���Ͽ� ����� 3������ ����Ÿ�� score ������ �����ؼ� �տ� 1 ~ 10�� �ڿ� 29990 ~ 29999���� ����غ�����.
// �����Ʈ
// ��������
// ����Ʈ
// ����Ʈ2


int main(void)
{
    //int DataSet[] = {6, 4, 2, 3, 1, 5}; 
    int Length = sizeof DataSet / sizeof DataSet[0];
    int i = 0;

    BubbleSort(DataSet, Length);

    printf("1~10��: \n");
    for (i = 0; i < 10; i++)
    {
        printf("��ȣ: %d, ����: %f\n", DataSet[i].number, DataSet[i].score);
    }

    printf("\n29990~29999��: \n");
    for (i = 29990; i <= 29999; i++)
    {
        printf("��ȣ: %d, ����: %f\n", DataSet[i].number, DataSet[i].score);
    }

    return 0;
}
*/