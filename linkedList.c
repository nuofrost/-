#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>




/**
 *  @name        : void *Create()
 *	@description : Create a linked list
 *	@param		 : None
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void *Create()
{
    LinkedList head;
    LinkedList p, s;
    ElemType x, cycle = 1;
    head = (LinkedList)malloc(sizeof(LNode));
    p = head;
    while(cycle)
    {
        printf("����������(����һ������������):");
        if(scanf("%d", &x) == 1)
        {
            s = (LinkedList)malloc(sizeof(LNode));
            s->data = x;
            p->next = s;
            p = s;
        }
        else
        {
            cycle = 0;
        }
    }
    printf("�ɹ�������һ������\n");
    p->next = NULL;
    return head;
}
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) { //����
	LinkedList list;
	list = (LinkedList)malloc(sizeof(LNode));
	if (list == NULL) {
		printf("�ڴ����ʧ��\n");
		return ERROR;
	}
	list->next = NULL;
	*L = list;
	return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) { //�ݻ٣�
	LinkedList p ;//��ʱ������
	while (*L != NULL) { //ʹ��ѭ����������Ҫ���жϣ�ȷ�ţ�
		p = *L;
		*L = (*L)->next;
		free(p);//�ͷ�ÿһ�����
	}
	printf("�ɹ�������һ������\n");
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, ElemType data) { //����
	LinkedList current = p;
	LinkedList newNode = (LinkedList)malloc(sizeof(LNode));
	if (newNode == NULL) {
		printf("�ڴ����ʧ�ܣ�");
		return ERROR;
	}
	newNode->data = data;
	newNode->next = NULL;
	while (current->next != NULL) { //����Ѱ��
		current = current->next;
	}
	current->next = newNode;//�ҵ��Ͳ����ȥ
	return SUCCESS;
}


/**
 *  @name        : Status DeleteList(LNode *p, ElemType e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType e) {
	LinkedList posNode = p->next;
	LinkedList posNodeFront = p;
	if (posNode == NULL) {
		printf("�����ǿյģ��޷�ɾ����");
	} else {
		while (posNode->data != e) {
			posNodeFront = posNode;
			posNode = posNode->next;
			if (posNode == NULL) {
				printf("û�и����ݡ�\n");
				return ERROR;
			}
		}
		posNodeFront->next = posNode ->next;
		free(posNode);
		return SUCCESS;
	}

}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	while (L != NULL) {
		if (L->data == e) {
			return SUCCESS;
		}
		L = L->next;
	}
	return ERROR;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	LinkedList p = L->next;
	while (p) {
		visit(p->data);
		p = p->next;
	}
	printf("\n");
}

void visit(ElemType e) {
	printf("%d->", e);
}