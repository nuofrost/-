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
	LinkedList head = NULL; //找链表头文件
	int flag = 0;//用于判断是否存在链表
	while (SUCCESS) { //头文件中的名字
		system("cls");//清屏
		printf("\n\n------------------------------\n");
		printf(">>> 1.Initialize.             \n");//初始化
		printf(">>> 2.Point.                  \n");//输入数据
		printf(">>> 3.Destroy.                \n");//销毁
		printf(">>> 4.Insert.                 \n");//插入
		printf(">>> 5.Delete.                 \n");//删除
		printf(">>> 6.traverse.               \n");//遍历数组
		printf(">>> 7.Search.                 \n");//搜索
		printf(">>> 8.Reverse.                \n");//反转
		printf(">>> 9.Reverse odd&even.       \n");//奇偶调换
		printf(">>> 10.Find MidNode.          \n");//找中点
		printf(">>> 11.Judge loop.            \n");//判断是否成环
		//嗯嗯
		printf(">>> 12.Exit.                  \n");//退出
		printf("------------------------------\n");
		if (flag) {
			TraverseList(head, visit); //如果存在链表的话就输出链表
		} else {
			printf("链表不存在。\n");//否则输出没有
		}
		printf("------------------------------\n");
		printf("----->>> 请输入你的选择：");
		switch (judge_int()) {
			case 1://创建空链表
				if (InitList(&head)) {
					printf("空链表创建成功。\n");
				} else {
					printf("空链表创建失败。\n");
				}
				break;
			case 2:
				head  = Create();
				flag = 1;
				break;
			case 3://销毁链表
				if (flag) {
					DestroyList(&head);
					flag = 0;
					break;
				} else {
					printf("链表不存在。\n");
				}
				break;
			case 4:
				if (flag) {
					int i;
					ElemType x;
					printf("插入位置：");
					scanf("%d", &x);
					InsertList(head, x);
				} else {
					printf("链表不存在\n");
				}
				break;
			case 5:
				if (flag) {
					ElemType x;
					printf("你想删除哪个数据：");
					scanf("%d", &x);
					if (DeleteList(head, x)) {
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
					TraverseList(head, visit);
				}
				break;
			}
			case 7: { //搜索数据
				ElemType x;
				printf("请输入你要查找的数据：");
				scanf("%d", &x);
				if (SearchList(head, x)) {
					printf("该数存在\n");
				} else {
					printf("该数不存在\n");
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
		printf("请输入数据(输入一个非整数结束):");
		if (scanf("%d", &x) == 1) {
			s = (LinkedList)malloc(sizeof(LNode));
			s->data = x;
			p->next = s;
			p = s;
		} else {
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