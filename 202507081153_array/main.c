#include <stdio.h>

// �迭
// ������ DataType�� ������ ���� �� �ʿ��� ��.

void SetArray(int* parray, int size) {
	for (int i = 0; i < size; i++) {
		parray[i] = i;
	}
}

void PrintArray(int* parray, int size) {
	for (int i = 0; i < size; i++) {
		printf("parray[%d] = %d\n", i, parray[i]);
	}
}

int main() {
	// DataType �迭��[����ǰ���];

	int array[10];

	// �迭���� �ּһ��

	//array = 10;

	int array2[100];

	SetArray(array2, 100);

	PrintArray(array2, 100);


	return 0;
}