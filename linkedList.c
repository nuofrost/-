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
        printf("请输入数据(输入一个非整数结束):");
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
    printf("成功创造了一个链表！\n");
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
Status InitList(LinkedList *L) { //生成
	LinkedList list;
	list = (LinkedList)malloc(sizeof(LNode));
	if (list == NULL) {
		printf("内存分配失败\n");
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
void DestroyList(LinkedList *L) { //摧毁！
	LinkedList p ;//临时链表结点
	while (*L != NULL) { //使用循环遍历做必要的判断（确信）
		p = *L;
		*L = (*L)->next;
		free(p);//释放每一个结点
	}
	printf("成功销毁了一个链表！\n");
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, ElemType data) { //插入
	LinkedList current = p;
	LinkedList newNode = (LinkedList)malloc(sizeof(LNode));
	if (newNode == NULL) {
		printf("内存分配失败！");
		return ERROR;
	}
	newNode->data = data;
	newNode->next = NULL;
	while (current->next != NULL) { //遍历寻找
		current = current->next;
	}
	current->next = newNode;//找到就插入进去
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
		printf("链表是空的，无法删除。");
	} else {
		while (posNode->data != e) {
			posNodeFront = posNode;
			posNode = posNode->next;
			if (posNode == NULL) {
				printf("没有该数据。\n");
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