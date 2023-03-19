#include "linkedList.h"
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
				head = Create();
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