#include "DoublyLinkedList.h"
#include "Score.h"
#include "ScoreData.h"


//1. 순차탐색
//순서대로 탐색
//#작동 순서
//탐색할 노드 NULL 확인
//Target Match 되는지 확인
//안되면 다음 -> 찾았으면 return
//끝까지 못 찾았으면 NULL일테니 위에서 거르기
Node* SequntialSearch(Node* Head, double Target)
{
	Node* Current = Head;
	while (Current != NULL) {
		if (Current->Data.score == Target) {
			return Current;
		}
		Current = Current->NextNode;
	}

	return NULL;
}

// 2. 전진이동법
// Target 매개변수에 전달된 값을 가진 노드를 찾고 해당 노드를 더블링크드 리스트의 맨앞으로 이동시킨다(헤드노드로 만들다.)
Node* MoveToFront(Node** Head, double Target) {
	Node* Current = (*Head);

	while (Current != NULL) {
		if (Current->Data.score == Target) {   // 찾는 값을 가진 노드를 찾음
			if (Current == (*Head)) {   // 1. 헤드노드인 경우
				return Current;
			}
			else if (Current->NextNode == NULL) {   // 2. 꼬리노드인 경우
				// Current 앞쪽 노드를 꼬리로 만든다.
				Current->PrevNode->NextNode = NULL;

				// Current를 헤드노드로 만든다.
				Current->PrevNode = NULL;
				Current->NextNode = (*Head);
				(*Head)->PrevNode = Current;

				(*Head) = Current;

				return Current;
			}
			else {
				// Current 링크에서 제거한다.
				Current->PrevNode->NextNode = Current->NextNode;
				Current->NextNode->PrevNode = Current->PrevNode;

				// Current를 헤드노드로 만든다.
				Current->PrevNode = NULL;
				Current->NextNode = (*Head);
				(*Head)->PrevNode = Current;

				(*Head) = Current;

				return Current;
			}
		}

		Current = Current->NextNode;
	}

	return NULL;

}


//3. 전위법
//한 칸 앞으로
Node* Transpose(Node** Head, double Target)
{
	Node* Current = (*Head);
	Node* Prev = NULL;
	Node* Next = NULL;

	while (Current != NULL) {
		if (Current->Data.score == Target) {
			if (Current == (*Head)) {
				return Current;
			}

			Prev = Current->PrevNode;
			Next = Current->NextNode;


			if (Prev == (*Head)) {
				(*Head) = Current;
			}
			else {
				Prev->PrevNode->NextNode = Current;
			}
			if (Next != NULL) {
				Next->PrevNode = Prev;
			}

			Current->PrevNode = Prev->PrevNode;
			Current->NextNode = Prev;
			Prev->PrevNode = Current;
			Prev->NextNode = Next;

			return Current;
		}

		Current = Current->NextNode;
	}

	return NULL;
}


//4. 계수법
//조회수(탐색횟수)에 따른 이동
Node* FrequencyMethod(Node** Head, double Target)
{


	return NULL;
}



int main(void)
{
	int   i = 0;
	int   Count = 0;
	Node* List = NULL;
	Node* NewNode = NULL;
	Node* Current = NULL;

	double InputValue = 0.0;	// 찾는 값(lf)을 저장하는 변수

	int Length = sizeof DataSet / sizeof DataSet[0];
	/*  노드 30,000개 추가 */
	for (i = 0; i < Length; i++)
	{
		NewNode = DLL_CreateNode(DataSet[i]);
		DLL_AppendNode(&List, NewNode);
	}

	//Current = DLL_CreateNode(8000);     // 8000값을 현재 노드로 만든다.
	//DLL_InsertNewHead(&List, Current);  //헤드 노드를 바꾼다.


	while (1) {
		printf("\n찾는 score값을 입력하세요: ");
		scanf_s("%lf", &InputValue);

		if (InputValue <= 0.0) {
			printf("찾는 작업을 중단하고 프로그램을 종료합니다.\n");
			break;
		}

		// Node* targetNode = SequntialSearch(List, InputValue);
		// Node* targetNode = MoveToFront(&List, InputValue);
		Node* targetNode = Transpose(&List, InputValue);
		// Node* targetNode = FrequencyMethod(&List, InputValue);

		if (targetNode != NULL) {	//찾는 Score값을 가진 노드를 찾은 경우
			printf("MATCH!!! searchValue: number:%d, score: %lf, Frequency: %d\n", targetNode->Data.number, targetNode->Data.score, targetNode->Frequency);
		}
		else {	// 찾는 score값을 가진 노드를 찾지 못함 (값이 없는 경우)
			printf("찾는 값을 가진 노드가 없음!!!\n");
		}

		// 앞에 10개
		for (int i = 0; i < 10; i++) {
			Current = DLL_GetNodeAt(List, i);
			printf("DataSet[%d] number:%d, score: %.4lf, Frequency: %d\n", i, Current->Data.number, Current->Data.score, Current->Frequency);
		}

		printf("===============================================================================\n");

		// 뒤에 10개
		for (int i = Length - 10; i < Length; i++) {
			Current = DLL_GetNodeAt(List, i);
			printf("DataSet[%d] number:%d, score: %.4lf, Frequency: %d\n", i, Current->Data.number, Current->Data.score, Current->Frequency);
		}

	}



	/*  모든 노드를 메모리에서 제거     */
	printf("\nDestroying List...\n");

	Count = DLL_GetNodeCount(List);

	for (i = 0; i < Count; i++)
	{
		Current = DLL_GetNodeAt(List, 0);

		if (Current != NULL)
		{
			DLL_RemoveNode(&List, Current);
			DLL_DestroyNode(Current);
		}
	}

	return 0;
}