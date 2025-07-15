#include "ArrayStack.h"

// 문제 1. 스택이 가득 찼는지 판단하는 함수를 만드세요.
/*
int AS_IsFull() {

}
*/

// 문제 2. 스택의 Capacity를 50개로 설정하고 while문으로 Stack이 가득 찰 때까지 100 처음 값을
// 증가시키면서 저장하고 스택이 빌 때까지 값을 출력해보세요.

// extra.
// 스택에 값을 push하다 용량이 부족하면 동적 배열의 용량을 2배 늘려서 값을 저장하도록 만들어보세요.
// 테스트 초기에 용량을 50개 설정하고 100개를 저장해서 값을 출력해보세요.

/*
=====================================================================
// 문제 1. 스택이 가득찼는지 판단하는 함수를 만드세요.
int AS_IsFull(ArrayStack* Stack) {
   if (Stack->Capacity == (Stack->Top + 1)) {
	  return 1;
   }
   else {
	  return 0;
   }

}

// 문제 2. 스택의 Capacity를 50개로 설정하고 while문으로 Stack이 가득 찰때까지 100처음 값을
// 증가시키면서 저장하고 스택이 빌때까지 값을 출력해보세요..

void Exer2() {
   ArrayStack* Stack = NULL;

   AS_CreateStack(&Stack, 50);

   int count = 100;

   while (!AS_IsFull(Stack)) {
	  AS_Push(Stack, count++);
   }

   while (!AS_IsEmpty(Stack)) {
	  printf("Popped %d\n", AS_Pop(Stack));
   }

}

// extra.
// 스택에 값을 push하다 용량이 부족하면 동적배열의 용량을 2배 늘려서 값을 저장하도록
// 만들어 보세요...
// 테스트 초기에 용량을 50개 설정하고 100개을 저장해서 값을 출력해보세요...
void AS_Push2(ArrayStack* Stack, ElementType Data)
{
   if (AS_IsFull(Stack)) { // 가득찼으면
	  Stack->Capacity = Stack->Capacity * 2; // 용량을 두배로 증가.
	  Stack->Nodes = realloc(Stack->Nodes, Stack->Capacity * sizeof(Node)); // 동적배열 재할당.
   }

   Stack->Top++;
   Stack->Nodes[Stack->Top].Data = Data;
}
*/

int main(void)
{
	int i = 0;
	ArrayStack* Stack = NULL;
	ArrayStack* Stack2 = NULL; // 문제 2 
	ArrayStack* Stack3 = NULL; // 문제 3

	AS_CreateStack(&Stack, 10);
	AS_CreateStack(&Stack2, 50); // 문제 2
	AS_CreateStack(&Stack3, 50); // 문제 3

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

	// 문제 2
	int j = 100;
	while (!AS_IsFull(Stack2))
	{
		AS_Push(Stack2, j++);
	}
	while (!AS_IsEmpty(Stack2))
	{
		printf("문제 2..Pop: %d\n", AS_Pop(Stack2));
	}

	// 문제 3 extra
	int k = 100;
	for (int i = 0; i < 100; i++)
	{
		AS_Push3(Stack3, k++);
	}
	while (!AS_IsEmpty(Stack3))
	{
		printf("문제3 extra..Pop: %d\n", AS_Pop(Stack3));
	}

	AS_DestroyStack(Stack);
	AS_DestroyStack(Stack2);
	AS_DestroyStack(Stack3);


	return 0;
}