/***************************************************************************************
 *	File Name				:	linkedList.h
 *	CopyRight				:	2020 QG Studio
 *	SYSTEM					:   win10
 *	Create Data				:	2020.3.28
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

/**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

/**************************************************************
*	Macro Define Section
**************************************************************/

#define OVERFLOW -1

/**************************************************************
*	Struct Define Section
**************************************************************/

// define element type
typedef int ElemType;

// define struct of linked list
typedef struct LNode {
	ElemType data;
	struct LNode *next;
} LNode, *LinkedList;

// define Status
typedef enum Status {
	ERROR,
	SUCCESS
} Status;


/**************************************************************
*	Prototype Declare Section
**************************************************************/


/**
 *  @name        : void *Create()
 *	@description : Create a linked list
 *	@param		 : None
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void *Create();
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L);

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L);

/**
 *  @name        : Status InsertList(LNode *p, ElemType data)
 *	@description : insert node q after node p
 *	@param		 : p, data
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, ElemType data);

/**
 *  @name        : Status DeleteList(LNode *p, ElemType e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType e);

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e));
void visit(ElemType e);
/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e);

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L);

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L);

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode *ReverseEvenList(LinkedList *L);

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode *FindMidNode(LinkedList *L);

/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif






#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int judge_int(void) { //��ֹ�û��������������ַ�
	int len, num = 0, arg = 1;
	char word[10];
	int m, j = 1, k;
	while (j) {
		scanf("%s", word);
		len = strlen(word);
		for (m = 0; m < len; m++) {
			if (word[m] < '0' || word[m] > '9') { //�����Ƿ��������������ַ�
				printf("������������");
				break;
			} else {
				if (m == len - 1)
					j = 0;
			}
		}
	}
	j = len - 1;
	for (m = 0; m < len; m++) { // ���ַ�����ת��Ϊ����
		for (k = 0; k < j; k++)
			arg *= 10;
		num += (word[m] - '0') * arg;
		arg = 1;
		j--;
	}
	return num;
}

int main() { //�ӿ��ļ������ļ�
	LinkedList head = NULL; //������ͷ�ļ�
	int flag = 0;//�����ж��Ƿ��������
	while (SUCCESS) { //ͷ�ļ��е�����
		system("cls");//����
		printf("\n\n------------------------------\n");
		printf(">>> 1.Initialize.             \n");//��ʼ��
		printf(">>> 2.Point.                  \n");//��������
		printf(">>> 3.Destroy.                \n");//����
		printf(">>> 4.Insert.                 \n");//����
		printf(">>> 5.Delete.                 \n");//ɾ��
		printf(">>> 6.traverse.               \n");//��������
		printf(">>> 7.Search.                 \n");//����
		printf(">>> 8.Reverse.                \n");//��ת
		printf(">>> 9.Reverse odd&even.       \n");//��ż����
		printf(">>> 10.Find MidNode.          \n");//���е�
		printf(">>> 11.Judge loop.            \n");//�ж��Ƿ�ɻ�
		//����
		printf(">>> 12.Exit.                  \n");//�˳�
		printf("------------------------------\n");
		if (flag) {
			TraverseList(head, visit); //�����������Ļ����������
		} else {
			printf("�������ڡ�\n");//�������û��
		}
		printf("------------------------------\n");
		printf("----->>> ���������ѡ��");
		switch (judge_int()) {
			case 1://����������
				if (InitList(&head)) {
					printf("���������ɹ���\n");
				} else {
					printf("��������ʧ�ܡ�\n");
				}
				break;
			case 2:
				head  = Create();
				flag = 1;
				break;
			case 3://��������
				if (flag) {
					DestroyList(&head);
					flag = 0;
					break;
				} else {
					printf("�������ڡ�\n");
				}
				break;
			case 4:
				if (flag) {
					int i;
					ElemType x;
					printf("����λ�ã�");
					scanf("%d", &x);
					InsertList(head, x);
				} else {
					printf("��������\n");
				}
				break;
			case 5:
				if (flag) {
					ElemType x;
					printf("����ɾ���ĸ����ݣ�");
					scanf("%d", &x);
					if (DeleteList(head, x)) {
						printf("����ɾ���ɹ�\n");
					} else {
						printf("����ɾ��ʧ��\n");
					}
					break;
				} else {
					printf("�������ڡ�\n");
				}
				break;
			case 6: { //��������
				if (head == NULL || head->next == NULL) {
					printf("�������ڻ���ֻ����һ���յ�ͷ���\n");
				} else {
					TraverseList(head, visit);
				}
				break;
			}
			case 7: { //��������
				ElemType x;
				printf("��������Ҫ���ҵ����ݣ�");
				scanf("%d", &x);
				if (SearchList(head, x)) {
					printf("��������\n");
				} else {
					printf("����������\n");
				}
				break;
			}
			case 12:
				exit(0);
			default:
				break;
		}
		system("pause");

	}
	return 0;
}

/**
 *  @name        : void *Create()
 *	@description : Create a linked list
 *	@param		 : None
 *	@return		 : L(the head pointer)
 *  @notice      : None
 */
void *Create() {
	LinkedList head;
	LinkedList p, s;
	ElemType x, cycle = 1;
	head = (LinkedList)malloc(sizeof(LNode));
	p = head;
	while (cycle) {
		printf("����������(����һ������������):");
		if (scanf("%d", &x) == 1) {
			s = (LinkedList)malloc(sizeof(LNode));
			s->data = x;
			p->next = s;
			p = s;
		} else {
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