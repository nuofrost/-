#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "duLinkedList.h"







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
