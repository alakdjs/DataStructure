#include <stdio.h>

// ��������

int main() {
	int a = 0;

	a = 20;

	printf("&a = %p\n", &a); // &: �ּҿ����� (������տ� ����ؼ� ������ �ּҰ��� �����ݴϴ�.)

	// ��������

	int* pa;  // ������ ���鶧 ����� *(asterisk)�� �������� �������Դϴ�.

	pa = &a;

	int** ppa;

	ppa = &pa;

	**ppa;  // �ּҰ� �տ� *(asterisk)�� ������ ������
	**&pa;
	*pa;
	*&a;
	a;

	printf("&**ppa = %p\n", &**ppa);
	printf("&**&pa = %p\n", &**&pa);
	printf("&*pa = %p\n", &*pa);
	printf("&*&a = %p\n", &*&a);
	printf("&a = %p\n", &a);

	*pa = 2000;

	printf("**ppa = %d\n", **ppa);
	printf("**&pa = %d\n", **&pa);
	printf("*pa = %d\n", *pa);
	printf("*&a = %d\n", *&a);
	printf("a = %d\n", a);


	return 0;
}