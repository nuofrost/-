
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/***************************************************************************************
 *	File Name				:	duLinkedList.h
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

#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED

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
typedef struct DuLNode {
	ElemType data;
	struct DuLNode *prior,  *next;
} DuLNode, *DuLinkedList;

// define status
typedef enum Status {
	ERROR,
	SUCCESS,
} Status;


/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L);

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L);

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q);

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q);

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType e);

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e));
void visit(ElemType e);

/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif




/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	DuLinkedList List;
	List = (DuLinkedList)malloc(sizeof(DuLNode));
	if (List == NULL) {
		printf("�ڴ����ʧ��\n");
		return ERROR;
	}
	List->next = NULL;
	List->prior = NULL;
	*L = List;
	return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	DuLinkedList temp;

	while (*L != NULL) {
		temp = *L;
		*L = (*L)->next;
		free(temp);
	}
	printf("���������٣�\n");
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	if (p->next == NULL) { //�����ǿյ�ʱ�����ֱ����ͨpq
		p->next = q;
		q->prior = p;
	} else { //ǰ��ͺ���ֱ��Ǻ�
		DuLinkedList temp;
		temp = p->next;
		p->next = q;
		q->next = temp;
		temp->prior = q;
		q->prior = p;
		return SUCCESS;
	}
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = q;
	q->prior = p;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType e) {
	if (p->next == NULL) {
		printf("�������ڡ�\n");
		return ERROR;
	} else {
		DuLinkedList posNode = p->next, posNodeFront = p;//�ҵ�ɾ������λ��
		while (posNode->data != e) {
			posNodeFront = posNode;
			posNode = posNode->next;//��������Ѱ��
			if (posNode == NULL) {
				printf("�Ҳ��������ݡ�\n");
				return ERROR;
			}
		}//�ҵ����˳�
		if (posNode->next != NULL) {
			posNodeFront->next = posNode->next;
			posNode->next->prior = posNodeFront;
		} else {
			posNodeFront->next = NULL;
		}
		free(posNode);//���ڴ�
		return SUCCESS;
	}
}




/**
 *  @data        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	DuLinkedList p = L->next;
	while (p) {
		visit(p->data);
		p = p->next;
	}
	printf("\n");
}

void visit(ElemType e) {
	printf("%d->", e);
}










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
	DuLinkedList head = NULL; //������ͷ�ļ�
	int flag = 0;//�����ж��Ƿ��������
	while (SUCCESS) { //ͷ�ļ��е�����
		system("cls");//����
		printf("\n\n------------------------------\n");
		printf(">>> 1.Initialize.             \n");//��ʼ��
		printf(">>> 2.Destroy.                \n");//����
		printf(">>> 3.BeforeInsert.           \n");//ͷ�巨����
		printf(">>> 4.AfterInsert.            \n");//β�巨����
		printf(">>> 5.Delete.                 \n");//ɾ��
		printf(">>> 6.traverse.               \n");//��������
		printf(">>> 7.Exit.                  \n");//�˳�
		printf("------------------------------\n");
		if (flag) {
			TraverseList_DuL(head, visit); //�����������Ļ����������
		}
		printf("------------------------------\n");
		printf("----->>> ���������ѡ��");
		switch (judge_int()) {
			case 1://����������
				if (InitList_DuL(&head)) {
					printf("���������ɹ���\n");
				} else {
					printf("��������ʧ�ܡ�\n");
				}
				break;
			case 2://��������
				if (flag) {
					DestroyList_DuL(&head);
					flag = 0;
					break;
				} else {
					printf("�������ڡ�\n");
				}
				break;
			case 3: { //ͷ�巨
				if (head == NULL) {
					printf("�������ڡ�\n");
				} else {
					DuLinkedList newNode;
					if (InitList_DuL(&newNode)) {
						printf("���������ݣ�");
						scanf("%d", &newNode->data);
						if (InsertBeforeList_DuL(head, newNode)) {
							printf("���ݲ���ɹ�\n");
						} else {
							printf("���ݲ���ʧ��\n");
						}
					} else {
						printf("���ݲ���ʧ��\n");
					}
				}
				break;
			}
			case 4: { //β�巨
				if (head == NULL) {
					printf("�������ڡ�\n");
				} else {
					DuLinkedList newNode;
					if (InitList_DuL(&newNode)) {
						printf("���������ݣ�");
						scanf("%d", &newNode->data);
						if (InsertAfterList_DuL(head, newNode)) {
							printf("���ݲ���ɹ�\n");
						} else {
							printf("���ݲ���ʧ��\n");
						}
					} else {
						printf("���ݲ���ʧ��\n");
					}
				}
				break;
			}
			case 5:
				if (flag) {
					ElemType x;
					printf("����ɾ���ĸ����ݣ�");
					scanf("%d", &x);
					if (DeleteList_DuL(head, x)) {
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
					TraverseList_DuL(head, visit);
				}
				break;
			}
			case 7:
				exit(0);
			default:
				break;
		}
		system("pause");

	}
	return 0;
}
