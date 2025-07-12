#include <stdio.h>

// �Լ� ������
// �Լ���

float add(int a, int b) {
	return a + (float)b;
}

float div(int a, int b) {
	return a / (float)b;
}

float threeMul(int a, int b, int c) {
	return a * b * c;
}

int main() {
	printf("&add = %p\n", &add);
	printf("&div = %p\n", &div);
	printf("&threeMul = %p\n", &threeMul);

	add(20, 30);
	// call add

	// �Լ�������
	int a = 20;
	int b = 30;
	float c = 0.0f;

	float(*pfunc)(int, int);   // �Լ� ������ ����

	pfunc = add;

	c = pfunc(a, b);
	printf("%d + %d = %d\n", a, b, c);

	pfunc = div;
	c = pfunc(a, b);
	printf("%d / %d = %f\n", a, b, c);

	// threeMul �Լ��� �Լ� ������ ������ �����
	// ���� ������ threeMul �Լ��� �ּҰ��� �����ϰ�
	// threeMul �Լ��� �ּҰ��� ������ ������ ���ڰ��� �����ؼ�
	// threeMul �Լ��� ȣ���ϰ� ������� ����غ�����...


	return 0;
}

