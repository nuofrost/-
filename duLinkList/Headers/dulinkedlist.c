#include <stdio.h>
#include <stdlib.h>
#include "DuLinkedList.h"




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