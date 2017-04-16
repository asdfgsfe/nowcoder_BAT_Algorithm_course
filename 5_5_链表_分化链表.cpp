#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode ListNode;
ListNode* listDivide(ListNode* head,int val);

struct ListNode {
	int val;
	struct ListNode *next;
};
//typedef struct List *ListNode;

int main()
{
	int a[] = { 1,4,5,2};

	ListNode* L=NULL;
	L = (ListNode *)malloc(sizeof(struct ListNode));
	L->val = a[0];
	L->next = NULL;

	ListNode* tmpNode;
	tmpNode = L;
	int i = 1;
	for (;i < 4;i++)
	{
		if (tmpNode->next == NULL)
		{
			ListNode* tmp=NULL;
			tmp = (ListNode *)malloc(sizeof(struct ListNode));
			tmp->val = a[i];
			tmp->next = NULL;
			tmpNode->next = tmp;
			tmpNode = tmpNode->next;
		}
	}
	ListNode* Head = listDivide( L,3);

	while (Head != NULL)
	{
		printf("%d\n", Head->val);
		Head = Head->next;
	}

	return 0;
}

//���Ĳ��� ÿִ��һ���Ͽ�����ͺ��沿�֣� ��if(greatHead==NULL) �ж��Ƿ������������ͷ��
		ListNode* listDivide(ListNode* head, int val) {
			// write code here
			if (head == NULL)
				return NULL;
			if (head->next == NULL)
				return head;
			ListNode* greatHead=NULL;
			ListNode* lessHead=NULL;
			ListNode* tmpLessNode = NULL;
			ListNode* tmpGreatNode = NULL;
			ListNode* tmpNode=NULL;

			while (head != NULL)
			{
				tmpNode = head->next;
				head->next = NULL;
				if (head->val>val)
				{
					if (greatHead == NULL)
					{
						greatHead = head;
						tmpGreatNode = head;					
					}
					else
					{
						tmpGreatNode->next = head;
						tmpGreatNode = tmpGreatNode->next;
					}
				}
				else
				{
					if (lessHead == NULL)
					{
						lessHead = head;
						tmpLessNode= head;
					}
					else
					{
						tmpLessNode->next = head;
						tmpLessNode = tmpLessNode->next;
					}
				}
				head = tmpNode;
			}
			tmpLessNode->next = greatHead;

			return lessHead;
}
