#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int moneyObject; // ���ǰ�
int moneyPay; // ���ұ�

void moneyCaCul()
{
	if (moneyObject < moneyPay)
	{
		int coin = moneyPay - moneyObject;
		int a = coin / 500;
		int b = (coin - (a * 500)) / 100;
		int c = (coin - (a * 500) - (b * 100)) / 50;
		int d = (coin - (a * 500) - (b * 100) - (c * 50)) / 10;
		int e = (coin - (a * 500) - (b * 100) - (c * 50) - (d * 10)) / 5;
		int f = (coin - (a * 500) - (b * 100) - (c * 50) - (d * 10) - (e * 5)) / 1;
		
		if (coin / 500 > 0)
		{
			printf("500�� %d��\n", a);
		}
		if (coin / 100 > 0)
		{
			printf("100�� %d��\n", b);
		}
		if (coin / 50 > 0)
		{
			printf("50�� %d��\n", c);
		}
		if (coin / 10 > 0)
		{
			printf("10�� %d��\n", d);
		}
		if (coin / 5 > 0)
		{
			printf("5�� %d��\n", e);
		}
		if (coin / 1 > 0)
		{
			printf("1�� %d��\n", f);
		}
		

	}
	else
		printf("���� �����մϴ�.\n");
}

int main(void)
{
	printf("���ǰ��� �Է��ϼ���: ");
	scanf("%d", &moneyObject);
	printf("���ұ��� �Է��ϼ���: ");
	scanf("%d", &moneyPay);
	printf("===== �Ž����� =====\n");
	moneyCaCul();
}