
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
		printf("内存分配失败\n");
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
	printf("链表已销毁！\n");
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	if (p->next == NULL) { //链表是空的时候可以直接连通pq
		p->next = q;
		q->prior = p;
	} else { //前面和后面分别标记好
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
		printf("链表不存在。\n");
		return ERROR;
	} else {
		DuLinkedList posNode = p->next, posNodeFront = p;//找到删除结点的位置
		while (posNode->data != e) {
			posNodeFront = posNode;
			posNode = posNode->next;//遍历链表寻找
			if (posNode == NULL) {
				printf("找不到该数据。\n");
				return ERROR;
			}
		}//找到就退出
		if (posNode->next != NULL) {
			posNodeFront->next = posNode->next;
			posNode->next->prior = posNodeFront;
		} else {
			posNodeFront->next = NULL;
		}
		free(posNode);//清内存
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










int judge_int(void) { //防止用户乱输入其他的字符
	int len, num = 0, arg = 1;
	char word[10];
	int m, j = 1, k;
	while (j) {
		scanf("%s", word);
		len = strlen(word);
		for (m = 0; m < len; m++) {
			if (word[m] < '0' || word[m] > '9') { //检验是否有乱输入其他字符
				printf("请输入整数：");
				break;
			} else {
				if (m == len - 1)
					j = 0;
			}
		}
	}
	j = len - 1;
	for (m = 0; m < len; m++) { // 将字符重新转换为数字
		for (k = 0; k < j; k++)
			arg *= 10;
		num += (word[m] - '0') * arg;
		arg = 1;
		j--;
	}
	return num;
}

int main() { //接口文件，主文件
	DuLinkedList head = NULL; //找链表头文件
	int flag = 0;//用于判断是否存在链表
	while (SUCCESS) { //头文件中的名字
		system("cls");//清屏
		printf("\n\n------------------------------\n");
		printf(">>> 1.Initialize.             \n");//初始化
		printf(">>> 2.Destroy.                \n");//销毁
		printf(">>> 3.BeforeInsert.           \n");//头插法插入
		printf(">>> 4.AfterInsert.            \n");//尾插法插入
		printf(">>> 5.Delete.                 \n");//删除
		printf(">>> 6.traverse.               \n");//遍历数组
		printf(">>> 7.Exit.                  \n");//退出
		printf("------------------------------\n");
		if (flag) {
			TraverseList_DuL(head, visit); //如果存在链表的话就输出链表
		}
		printf("------------------------------\n");
		printf("----->>> 请输入你的选择：");
		switch (judge_int()) {
			case 1://创建空链表
				if (InitList_DuL(&head)) {
					printf("空链表创建成功。\n");
				} else {
					printf("空链表创建失败。\n");
				}
				break;
			case 2://销毁链表
				if (flag) {
					DestroyList_DuL(&head);
					flag = 0;
					break;
				} else {
					printf("链表不存在。\n");
				}
				break;
			case 3: { //头插法
				if (head == NULL) {
					printf("链表不存在。\n");
				} else {
					DuLinkedList newNode;
					if (InitList_DuL(&newNode)) {
						printf("请输入数据：");
						scanf("%d", &newNode->data);
						if (InsertBeforeList_DuL(head, newNode)) {
							printf("数据插入成功\n");
						} else {
							printf("数据插入失败\n");
						}
					} else {
						printf("数据插入失败\n");
					}
				}
				break;
			}
			case 4: { //尾插法
				if (head == NULL) {
					printf("链表不存在。\n");
				} else {
					DuLinkedList newNode;
					if (InitList_DuL(&newNode)) {
						printf("请输入数据：");
						scanf("%d", &newNode->data);
						if (InsertAfterList_DuL(head, newNode)) {
							printf("数据插入成功\n");
						} else {
							printf("数据插入失败\n");
						}
					} else {
						printf("数据插入失败\n");
					}
				}
				break;
			}
			case 5:
				if (flag) {
					ElemType x;
					printf("你想删除哪个数据：");
					scanf("%d", &x);
					if (DeleteList_DuL(head, x)) {
						printf("数据删除成功\n");
					} else {
						printf("数据删除失败\n");
					}
					break;
				} else {
					printf("链表不存在。\n");
				}
				break;
			case 6: { //遍历数组
				if (head == NULL || head->next == NULL) {
					printf("链表不存在或者只存在一个空的头结点\n");
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
