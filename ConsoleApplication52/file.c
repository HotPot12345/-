#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;

};
struct Node *list = NULL;

struct Node* creatList()
{
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	headNode->next = NULL;

	return headNode;
}
struct Node* creatNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->next = NULL;
	newNode->data = data;

	return newNode;
}
void InsertNode(struct Node* headNode, int data)
{
	struct Node* newNode = creatNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;

}
void PrintList(struct Node* headNode)
{
	struct Node* p = headNode->next;
	if (p == NULL){
		printf("������Ϊ�գ�\n");
		return;
	}
	else
	{
		while (p != NULL)
		{
			printf("%d ", p->data);

			p = p->next;
		}
		printf("\n");
	}
}
void deleteNode(struct Node* headNode)
{
	int n;
	struct Node* pre, *p;
	pre = headNode;
	p = headNode->next;
	printf("������Ҫɾ���Ľڵ㣺");
	scanf("%d", &n);
	if (p == NULL){
		printf("������Ϊ�գ�\n");
		return;
	}
	else
	{
		while (p->data != n){
			pre = p;
			p = p->next;
			if (p == NULL){
				printf("δ�ҵ�������ݣ�\n");
				return;
			}
		}
		pre->next = p->next;
		free(p);
	}

	
}
void ComprehensiveSort(struct Node* headNode)
{
	struct Node *pre, *p;
	int t;
	pre = headNode->next;
	p = pre->next;
	if (pre == NULL || p == NULL)			//preΪ�գ���ʾ������Ϊ������pre��Ϊ�գ�pΪ��ʱ������������ֻ��һ��Ԫ����������
	{
		return;
	}
	while (pre != NULL)
	{
		while (p != NULL)
		{
			if (pre->data > p->data){
				t = pre->data;
				pre->data = p->data;
				p->data = t;
			}
			p = p->next;
		}
		pre = pre->next;
		p = pre->next;
		if (p == NULL)return;
	}

}
int main()
{
	list = creatList();
	InsertNode(list,1);
	InsertNode(list,2);
	InsertNode(list, 3);
	PrintList(list);
	ComprehensiveSort(list);
	PrintList(list);
	return 0;
}