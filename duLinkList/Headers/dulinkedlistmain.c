#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "duLinkedList.h"







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
