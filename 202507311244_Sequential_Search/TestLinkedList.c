#include "LinkedList.h"
#include "Score.h"
#include "ScoreData.h"

// 1. ����Ž��
// �̱۸�ũ�� ����Ʈ�� ����� 3������ ����Ÿ �ȿ��� Target�Ű������� ���޵� ���� ���� ��带 ã��
// �ش� ����� �ּҰ��� �����Ѵ�.
Node* SequentialSearch(Node* Head, double Target) {

	Node* Current = Head;

	while (Current != NULL) {
		if (Current->Data.score == Target)
			return Current;

		Current = Current->NextNode;
	}
	return NULL;
}


// 2. �����̵���
// Target �Ű������� ���޵� ���� ���� ��带 ã�� �ش� ��带 �̱۸�ũ�� ����Ʈ�� �Ǿ����� �̵���Ų��(������ �����.)
// ����� �� (ã�� ���� ������ �ִ� ����� ��ġ)
// 1. Head ����� ���
// 2. ��������� ���
// 3. �̿��� ���
Node* MoveToFront(Node** Head, double Target) {

	Node* Current = (*Head);
	Node* Prev = NULL;

	while (Current != NULL) {
		if (Current->Data.score == Target) { // ã�� ���� ���� ��带 ã��
			if (Current == (*Head)) {	 // 1. ã�� ���� ���� ��尡 ������� ���
				return Current;
			}
			else if (Current->NextNode == NULL) {  // 2. ã�� ���� ���� ��尡 ������� ���
				Prev->NextNode = NULL;			// Current�� ������带 �������� �����.

				// Current��带 ������ �����.
				Current->NextNode = (*Head); // Current �������� ������ ������� �ּҰ��� ����
				(*Head) = Current; // Main�� List(*Head)������ Current�� ������� �ּҰ����� �����Ѵ�.

				return Current;
			}
			else {	// 3. ã�� ���� ���� ��尡 ��嵵 ������嵵 �ƴ� ���
				// Current�� ��ũ���� �����Ѵ�.
				Prev->NextNode = Current->NextNode;

				// Current�� ������ �����.
				Current->NextNode = (*Head);
				(*Head) = Current;

				return Current;
			}
		}
		Prev = Current;
		Current = Current->NextNode;	// ���� ��带 ����Ų��.
	}

	return NULL;
}

// 3. ������
// Target �Ű������� ���޵� ���� ���� ��带 ã�� �ش� ��带 �̱۸�ũ�� ����Ʈ����
// ã�� ��带 ��ĭ �������� �̵���Ų��.
// ����� �� (ã�� ���� ������ �ִ� ����� ��ġ)
// 1. Head ����� ���
// 2. ��������� ���
// 3. Head ��� ������ ���
// 4. �̿��� ���
Node* Transpose(Node** Head, double Target) {
	Node* Current = *Head;
	Node* Prev = NULL;
	Node* PPrev = NULL;

	while (Current != NULL) {
		if (Current->Data.score == Target) {   // ã�� ���� ���� ��带 ã��.
			if (Current == (*Head)) {   // 1. ã�� ���� ���� ��尡 ������� ���
				return Current;
			}
			else if (Current->NextNode == NULL) {   // 2. ã�� ���� ���� ��尡 ��������� ���
				// Current�� ��ũ���� �����Ѵ�.
				// Prev->NextNode = NULL;
				Prev->NextNode = Current->NextNode;

				// PPrev�� Prev ���̿� Current ��带 �����Ѵ�.
				Current->NextNode = Prev;
				PPrev->NextNode = Current;

				return Current;
			}
			else if ((*Head)->NextNode == Current) { // 3. Current�� ����� ���� �� ���
				// Current�� ��ũ���� �����Ѵ�.
				(*Head)->NextNode = Current->NextNode;
				// Prev->NextNode = Current->NextNode;

				// Current�� ������ �����.
				Current->NextNode = (*Head);
				(*Head) = Current;

				return Current;
			}
			else {   // 4. �̿��� ���
				// Current�� ��ũ���� �����Ѵ�.
				Prev->NextNode = Current->NextNode;

				// Current�� PPrev(��������� �������)�� Prev(�������) ���̿� �����Ѵ�.
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

// 4. �����
// Node�� �󵵼�(Frequency)�� �����ϴ� ������ ����� o
// Target�� ���޵� ���� ���� ��带 ã�� �� �󵵼��� ������Ű�� o
// �󵵼��� ũ�⸦ ���Ͽ� �ش� ��带 ��ġ ��Ų��.
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
	Node* List = NULL;  // ������ּҰ��� ����
	Node* Current = NULL;
	Node* NewNode = NULL;

	double InputValue = 0.0;	// ã�� ���� �����ϴ� ����

	int Length = sizeof(DataSet) / sizeof(Score);	// DataSet �迭����� ���� (30000��)

	//  ��� 30000�� �߰� 
	for (i = 0; i < Length; i++)
	{
		NewNode = SLL_CreateNode(DataSet[i]);
		NewNode->Frequency = 0;
		SLL_AppendNode(&List, NewNode);
	}

	// ã�� ���� ã�� �ݺ�����
	while (1) {
		printf("\nã�� score���� �Է��ϼ���: ");
		scanf_s("%lf", &InputValue);

		if (InputValue <= 0.0) {
			printf("ã�� �۾��� �ߴ��ϰ� ���α׷��� �����մϴ�.\n");
			break;
		}

		Node* targetNode = FrequencyMethod(&List, InputValue);

		if (targetNode != NULL) {	// ã�� score���� ���� ��带 ã�� ���
			printf("MATCH!!! searchValue: number:%d, score: %lf, Frequency: %d\n", targetNode->Data.number, targetNode->Data.score, targetNode->Frequency);
		}
		else {	// ã�� score���� ���� ��带 �� ã�� ���
			printf("ã�� ���� ���� ��尡 ����!!!!\n");
		}

		// �տ� 10��
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



	//  ��� ��带 �޸𸮿��� ����     
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
