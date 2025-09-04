#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int moneyObject; // 물건값
int moneyPay; // 지불금

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
			printf("500원 %d개\n", a);
		}
		if (coin / 100 > 0)
		{
			printf("100원 %d개\n", b);
		}
		if (coin / 50 > 0)
		{
			printf("50원 %d개\n", c);
		}
		if (coin / 10 > 0)
		{
			printf("10원 %d개\n", d);
		}
		if (coin / 5 > 0)
		{
			printf("5원 %d개\n", e);
		}
		if (coin / 1 > 0)
		{
			printf("1원 %d개\n", f);
		}
		

	}
	else
		printf("돈이 부족합니다.\n");
}

int main(void)
{
	printf("물건값을 입력하세요: ");
	scanf("%d", &moneyObject);
	printf("지불금을 입력하세요: ");
	scanf("%d", &moneyPay);
	printf("===== 거스름돈 =====\n");
	moneyCaCul();
}