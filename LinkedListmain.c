#include "linkedList.h"
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
				head = Create();
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