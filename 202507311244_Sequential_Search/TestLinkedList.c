#include "LinkedList.h"
#include "Score.h"
#include "ScoreData.h"

// 1. 순차탐색
// 싱글링크드 리스트에 저장된 3만개의 데이타 안에서 Target매개변수에 전달된 값을 가진 노드를 찾고
// 해당 노드의 주소값을 전달한다.
Node* SequentialSearch(Node* Head, double Target) {

	Node* Current = Head;

	while (Current != NULL) {
		if (Current->Data.score == Target)
			return Current;

		Current = Current->NextNode;
	}
	return NULL;
}


// 2. 전진이동법
// Target 매개변수에 전달된 값을 가진 노드를 찾고 해당 노드를 싱글링크드 리스트의 맨앞으로 이동시킨다(헤드노드로 만들다.)
// 경우의 수 (찾는 값을 가지고 있는 노드의 위치)
// 1. Head 노드인 경우
// 2. 꼬리노드인 경우
// 3. 이외의 경우
Node* MoveToFront(Node** Head, double Target) {

	Node* Current = (*Head);
	Node* Prev = NULL;

	while (Current != NULL) {
		if (Current->Data.score == Target) { // 찾는 값을 가진 노드를 찾음
			if (Current == (*Head)) {	 // 1. 찾는 값을 가진 노드가 헤드노드인 경우
				return Current;
			}
			else if (Current->NextNode == NULL) {  // 2. 찾는 값을 가진 노드가 헤드노드인 경우
				Prev->NextNode = NULL;			// Current의 이전노드를 꼬리노드로 만든다.

				// Current노드를 헤드노드로 만든다.
				Current->NextNode = (*Head); // Current 다음노드로 현재의 헤드노드의 주소값을 저장
				(*Head) = Current; // Main의 List(*Head)변수에 Current를 헤드노드의 주소값으로 갱신한다.

				return Current;
			}
			else {	// 3. 찾는 값을 가진 노드가 헤드도 꼬리노드도 아닌 경우
				// Current를 링크에서 제거한다.
				Prev->NextNode = Current->NextNode;

				// Current를 헤드노드로 만든다.
				Current->NextNode = (*Head);
				(*Head) = Current;

				return Current;
			}
		}
		Prev = Current;
		Current = Current->NextNode;	// 다음 노드를 가리킨다.
	}

	return NULL;
}

// 3. 전위법
// Target 매개변수에 전달된 값을 가진 노드를 찾고 해당 노드를 싱글링크드 리스트에서
// 찾는 노드를 한칸 앞쪽으로 이동시킨다.
// 경우의 수 (찾는 값을 가지고 있는 노드의 위치)
// 1. Head 노드인 경우
// 2. 꼬리노드인 경우
// 3. Head 노드 다음인 경우
// 4. 이외의 경우
Node* Transpose(Node** Head, double Target) {
	Node* Current = *Head;
	Node* Prev = NULL;
	Node* PPrev = NULL;

	while (Current != NULL) {
		if (Current->Data.score == Target) {   // 찾는 값을 가진 노드를 찾음.
			if (Current == (*Head)) {   // 1. 찾는 값을 가진 노드가 헤드노드인 경우
				return Current;
			}
			else if (Current->NextNode == NULL) {   // 2. 찾는 값을 가진 노드가 꼬리노드인 경우
				// Current를 링크에서 제거한다.
				// Prev->NextNode = NULL;
				Prev->NextNode = Current->NextNode;

				// PPrev와 Prev 사이에 Current 노드를 삽입한다.
				Current->NextNode = Prev;
				PPrev->NextNode = Current;

				return Current;
			}
			else if ((*Head)->NextNode == Current) { // 3. Current가 헤드노드 다음 인 경우
				// Current를 링크에서 제거한다.
				(*Head)->NextNode = Current->NextNode;
				// Prev->NextNode = Current->NextNode;

				// Current를 헤드노드로 만든다.
				Current->NextNode = (*Head);
				(*Head) = Current;

				return Current;
			}
			else {   // 4. 이외의 경우
				// Current를 링크에서 제거한다.
				Prev->NextNode = Current->NextNode;

				// Current를 PPrev(이전노드의 이전노드)와 Prev(이전노드) 사이에 삽입한다.
				Current->NextNode = Prev;
				PPrev->NextNode = Current;

				return Current;
			}

		}

		PPrev = Prev;
		Prev = Current;
		Current = Current->NextNode;
	}

	return NULL;
}

// 4. 계수법
// Node에 빈도수(Frequency)를 저장하는 변수를 만들고 o
// Target에 전달된 값을 가진 노드를 찾은 후 빈도수를 증가시키고 o
// 빈도수에 크기를 비교하여 해당 노드를 위치 시킨다.
Node* FrequencyMethod(Node** Head, double Target) {
	
	Node* Current = *Head;
	Node* Prev = NULL;

	while (Current != NULL) {
		if (Current->Data.score == Target) {
			Current->Frequency++;

			if (Prev != NULL) {
				Prev->NextNode = Current->NextNode;
			}
			else {
				return Current;
			}

			Node* Find = *Head;
			Node* FindPrev = NULL;

			while (Find != Current && Find->Frequency >= Current->Frequency) {
				FindPrev = Find;
				Find = Find->NextNode;
			}

			if (FindPrev == NULL) {
				Current->NextNode = *Head;
				*Head = Current;
			}
			else {
				Current->NextNode = Find;
				FindPrev->NextNode = Current;
			}

			return Current;
		}

		Prev = Current;
		Current = Current->NextNode;

	}

	return NULL;
}

int main(void)
{
	int   i = 0;
	int   Count = 0;
	Node* List = NULL;  // 헤드노드주소값을 저장
	Node* Current = NULL;
	Node* NewNode = NULL;

	double InputValue = 0.0;	// 찾는 값을 저장하는 변수

	int Length = sizeof(DataSet) / sizeof(Score);	// DataSet 배열요소의 갯수 (30000개)

	//  노드 30000개 추가 
	for (i = 0; i < Length; i++)
	{
		NewNode = SLL_CreateNode(DataSet[i]);
		NewNode->Frequency = 0;
		SLL_AppendNode(&List, NewNode);
	}

	// 찾는 값을 찾는 반복연산
	while (1) {
		printf("\n찾는 score값을 입력하세요: ");
		scanf_s("%lf", &InputValue);

		if (InputValue <= 0.0) {
			printf("찾는 작업을 중단하고 프로그램을 종료합니다.\n");
			break;
		}

		Node* targetNode = FrequencyMethod(&List, InputValue);

		if (targetNode != NULL) {	// 찾는 score값을 가진 노드를 찾은 경우
			printf("MATCH!!! searchValue: number:%d, score: %lf, Frequency: %d\n", targetNode->Data.number, targetNode->Data.score, targetNode->Frequency);
		}
		else {	// 찾는 score값을 가진 노드를 못 찾은 경우
			printf("찾는 값을 가진 노드가 없음!!!!\n");
		}

		// 앞에 10개
		for (int i = 0; i < 10; i++) {
			Current = SLL_GetNodeAt(List, i);
			printf("DataSet[%d] number:%d, score: %.4lf, Frequency: %d\n", i, Current->Data.number, Current->Data.score, Current->Frequency);
		}

		printf("===============================================\n");

		for (int i = Length - 10; i < Length; i++) {
			Current = SLL_GetNodeAt(List, i);
			printf("DataSet[%d] number:%d, score: %.4lf, Frequency: %d\n", i, Current->Data.number, Current->Data.score, Current->Frequency);
		}

	}



	//  모든 노드를 메모리에서 제거     
	printf("\nDestroying List...\n");

	for (i = 0; i < Count; i++)
	{
		Current = SLL_GetNodeAt(List, 0);

		if (Current != NULL)
		{
			SLL_RemoveNode(&List, Current);
			SLL_DestroyNode(Current);
		}
	}

	return 0;
}
