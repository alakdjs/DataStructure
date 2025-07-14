#include "ArrayStack.h"

// ���� 1. ������ ���� á���� �Ǵ��ϴ� �Լ��� ���弼��.
/*
int AS_IsFull() {

}
*/

// ���� 2. ������ Capacity�� 50���� �����ϰ� while������ Stack�� ���� �� ������ 100 ó�� ����
// ������Ű�鼭 �����ϰ� ������ �� ������ ���� ����غ�����.

// extra.
// ���ÿ� ���� push�ϴ� �뷮�� �����ϸ� ���� �迭�� �뷮�� 2�� �÷��� ���� �����ϵ��� ��������.
// �׽�Ʈ �ʱ⿡ �뷮�� 50�� �����ϰ� 100���� �����ؼ� ���� ����غ�����.

int main(void)
{
	int i = 0;
	ArrayStack* Stack = NULL;
	ArrayStack* Stack2 = NULL; // ���� 2 
	ArrayStack* Stack3 = NULL; // ���� 3

	AS_CreateStack(&Stack, 10);
	AS_CreateStack(&Stack2, 50); // ���� 2
	AS_CreateStack(&Stack3, 50); // ���� 3

	AS_Push(Stack, 3);
	AS_Push(Stack, 37);
	AS_Push(Stack, 11);
	AS_Push(Stack, 12);

	printf("Capacity: %d, Size: %d, Top: %d\n\n", Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));

	for (i = 0; i < 4; i++)
	{
		if (AS_IsEmpty(Stack))
			break;

		printf("Popped: %d, ", AS_Pop(Stack));

		if (!AS_IsEmpty(Stack))
			printf("Current Top: %d\n", AS_Top(Stack));
		else
			printf("Stack Is Empty.\n");
	}

	// ���� 2
	int j = 100;
	while (!AS_IsFull(Stack2))
	{
		AS_Push(Stack2, j++);
	}
	while (!AS_IsEmpty(Stack2))
	{
		printf("���� 2..Pop: %d\n", AS_Pop(Stack2));
	}

	// ���� 3 extra
	int k = 100;
	for (int i = 0; i < 100; i++)
	{
		AS_Push3(Stack3, k++);
	}
	while (!AS_IsEmpty(Stack3))
	{
		printf("����3 extra..Pop: %d\n", AS_Pop(Stack3));
	}

	AS_DestroyStack(Stack);
	AS_DestroyStack(Stack2);
	AS_DestroyStack(Stack3);


	return 0;
}