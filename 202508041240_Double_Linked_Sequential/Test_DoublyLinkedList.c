#include "DoublyLinkedList.h"
#include "Score.h"
#include "ScoreData.h"


//1. ����Ž��
//������� Ž��
//#�۵� ����
//Ž���� ��� NULL Ȯ��
//Target Match �Ǵ��� Ȯ��
//�ȵǸ� ���� -> ã������ return
//������ �� ã������ NULL���״� ������ �Ÿ���
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

// 2. �����̵���
// Target �Ű������� ���޵� ���� ���� ��带 ã�� �ش� ��带 ����ũ�� ����Ʈ�� �Ǿ����� �̵���Ų��(������ �����.)
Node* MoveToFront(Node** Head, double Target) {
	Node* Current = (*Head);

	while (Current != NULL) {
		if (Current->Data.score == Target) {   // ã�� ���� ���� ��带 ã��
			if (Current == (*Head)) {   // 1. ������� ���
				return Current;
			}
			else if (Current->NextNode == NULL) {   // 2. ��������� ���
				// Current ���� ��带 ������ �����.
				Current->PrevNode->NextNode = NULL;

				// Current�� ������ �����.
				Current->PrevNode = NULL;
				Current->NextNode = (*Head);
				(*Head)->PrevNode = Current;

				(*Head) = Current;

				return Current;
			}
			else {
				// Current ��ũ���� �����Ѵ�.
				Current->PrevNode->NextNode = Current->NextNode;
				Current->NextNode->PrevNode = Current->PrevNode;

				// Current�� ������ �����.
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


//3. ������
//�� ĭ ������
Node* Transpose(Node** Head, double Target)
{
	Node* Current = (*Head);

	while (Current != NULL) {

		if (Current->Data.score == Target) {   // ã�� ���� ���� ��带 ã�´�.

			// ã�� ���� ���� ��带 ã��.
			if (Current == (*Head)) { // 1. Current�� ������� ���
				return Current;
			}
			else if (Current->NextNode == NULL) {   // 2. Current�� ��������� ���
				// Current�� ��ũ���� �����Ѵ�.
				Current->PrevNode->NextNode = NULL; // Current�� ���ʳ�带 �������� ����

				// Current�� ���ʳ��� �վ��ʳ�� ���̿� ����
				Current->NextNode = Current->PrevNode;
				Current->PrevNode = Current->PrevNode->PrevNode;

				Current->NextNode->PrevNode = Current;
				Current->PrevNode->NextNode = Current;

				return Current;
			}
			else if (Current == (*Head)->NextNode) {   // 3. Current�� ����� �����ΰ��

				// Current�� ��ũ���� �����Ѵ�.
				Current->NextNode->PrevNode = Current->PrevNode;
				Current->PrevNode->NextNode = Current->NextNode;

				// Current�� ������ �����.
				Current->PrevNode = NULL;
				Current->NextNode = (*Head);
				(*Head)->PrevNode = Current;

				(*Head) = Current;

				return Current;
			}
			else { // 4. �̿��� ��� (��嵵 �ƴϰ�, ��� �������ƴϰ�, ������ �ƴѰ��)
				// Current�� ��ũ���� �����Ѵ�.
				Current->PrevNode->NextNode = Current->NextNode;
				Current->NextNode->PrevNode = Current->PrevNode;

				// Current��带 �ճ��� �վճ�� ���̿� �����Ѵ�.
				Current->NextNode = Current->PrevNode;
				Current->PrevNode = Current->PrevNode->PrevNode;

				Current->PrevNode->NextNode = Current;
				Current->NextNode->PrevNode = Current;

				return Current;
			}
		}

		Current = Current->NextNode;
	}

	return NULL;

}


//4. �����
//��ȸ��(Ž��Ƚ��)�� ���� �̵�
Node* FrequencyMethod(Node** Head, double Target)
{
	Node* Current = (*Head);

	while (Current != NULL) {
		if (Current->Data.score == Target) {  // ã�� ���� ���� ��带 ã�´�.
			// ã�� ���� ���� ��带 ã��.
			// �󵵼��� ���� ��Ŵ.
			Current->Frequency++;

			if (Current == (*Head)) {   // 1. ã�� ���� ���� ��尡 ������� ���
				return Current;
			}
			else { // 2. ã�� ���� ���� ��尡 ����尡 �ƴ� ���
				if (Current->PrevNode->Frequency >= Current->Frequency) { // ���ʳ���� �󵵼��� Current�� �󵵼����� ũ�ų� ���� ���
					return Current;
				}
				else {  // ���� ����� �󵵼���  Current�� �󵵼����� ���� ���

					// Current��带 ��ũ���� �����Ѵ�.
					Current->PrevNode->NextNode = Current->NextNode;
					if (Current->NextNode != NULL) {
						Current->NextNode->PrevNode = Current->PrevNode;
					}

					// FindNode�� ������ġ�� ã�´�.
					Node* FindNode = Current;

					Current = (*Head);

					while (Current != NULL) {
						if (Current->Frequency < FindNode->Frequency) {   // Current�� �󵵼��� FindNode�� �󵵼����� ���� ���.

							if (Current == (*Head)) {   // Current��尡 ��� ����� ���, FindNode�� ������ �����.
								FindNode->NextNode = Current;
								Current->PrevNode = FindNode;
								FindNode->PrevNode = NULL;

								(*Head) = FindNode;
								return Current;
							}
							else {   // Current�� ��� ��尡 �ƴ� ���, FindNode�� Current����� ���ʿ� �����Ѵ�.

								FindNode->NextNode = Current;
								FindNode->PrevNode = Current->PrevNode;

								FindNode->PrevNode->NextNode = FindNode;
								FindNode->NextNode->PrevNode = FindNode;

								return Current;
							}
						}

						Current = Current->NextNode;
					}


				}

			}

		}


		Current = Current->NextNode;
	}

	return NULL;
}



int main(void)
{
	int   i = 0;
	int   Count = 0;
	Node* List = NULL;
	Node* NewNode = NULL;
	Node* Current = NULL;

	double InputValue = 0.0;	// ã�� ��(lf)�� �����ϴ� ����

	int Length = sizeof DataSet / sizeof DataSet[0];
	/*  ��� 30,000�� �߰� */
	for (i = 0; i < Length; i++)
	{
		NewNode = DLL_CreateNode(DataSet[i]);
		DLL_AppendNode(&List, NewNode);
	}

	//Current = DLL_CreateNode(8000);     // 8000���� ���� ���� �����.
	//DLL_InsertNewHead(&List, Current);  //��� ��带 �ٲ۴�.


	while (1) {
		printf("\nã�� score���� �Է��ϼ���: ");
		scanf_s("%lf", &InputValue);

		if (InputValue <= 0.0) {
			printf("ã�� �۾��� �ߴ��ϰ� ���α׷��� �����մϴ�.\n");
			break;
		}

		// Node* targetNode = SequntialSearch(List, InputValue);
		// Node* targetNode = MoveToFront(&List, InputValue);
		// Node* targetNode = Transpose(&List, InputValue);
		Node* targetNode = FrequencyMethod(&List, InputValue);

		if (targetNode != NULL) {	//ã�� Score���� ���� ��带 ã�� ���
			printf("MATCH!!! searchValue: number:%d, score: %lf, Frequency: %d\n", targetNode->Data.number, targetNode->Data.score, targetNode->Frequency);
		}
		else {	// ã�� score���� ���� ��带 ã�� ���� (���� ���� ���)
			printf("ã�� ���� ���� ��尡 ����!!!\n");
		}

		// �տ� 10��
		for (int i = 0; i < 10; i++) {
			Current = DLL_GetNodeAt(List, i);
			printf("DataSet[%d] number:%d, score: %.4lf, Frequency: %d\n", i, Current->Data.number, Current->Data.score, Current->Frequency);
		}

		printf("===============================================================================\n");

		// �ڿ� 10��
		for (int i = Length - 10; i < Length; i++) {
			Current = DLL_GetNodeAt(List, i);
			printf("DataSet[%d] number:%d, score: %.4lf, Frequency: %d\n", i, Current->Data.number, Current->Data.score, Current->Frequency);
		}

	}



	/*  ��� ��带 �޸𸮿��� ����     */
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