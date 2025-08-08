#define _CRT_SECURE_NO_WARNINGS
#include "LinkedQueue.h"

int main( void )
{
    Node* Popped;
    LinkedQueue* Queue;

    LQ_CreateQueue(&Queue );

    char data[100];     // ���ڿ� �Է� ����
    int priority = 0;   // �켱 ���� �Է¿�

    while (1) {
        printf("�켱���� ť�� ������ �����͸� �Է��ϼ���: ");
        scanf("%d %s", &priority, data);

        if (priority <= -1) break;  // �Է� �ߴ�.
        
        // �Է¹��� �����͸� ť�� �����Ѵ�.
        LQ_Enqueue(Queue, LQ_CreateNode(priority, data));

        
        // ť�� �Էµ� �����͸� ���
        Node* Current = Queue->Front;   // ������� �ּҰ��� Current�� ����

        while (Current != NULL) {
            printf("[priority: %d, Data: %s\n", Current->priority, Current->Data);

            Current = Current->NextNode;
        }
    }
    
    while ( LQ_IsEmpty( Queue ) == 0 )
    {
        Popped = LQ_Dequeue( Queue );

        printf( "Dequeue: %s \n", Popped->Data );

        LQ_DestroyNode( Popped );
    }

    LQ_DestroyQueue( Queue );

    return 0;
}