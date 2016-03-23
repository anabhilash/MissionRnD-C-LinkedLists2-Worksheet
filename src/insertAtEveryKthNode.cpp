/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node
{
	int num;
	struct node *next;
};
void insert(struct node *, int);

struct node * insertAtEveryKthNode(struct node *head, int K) 
{
	int count = 0;
	struct node *temp1;
	if (K<=0)
		return NULL;
	else
	{
		temp1 = head;
		while (temp1 != NULL)
		{
			count++;
			if (count == K)
			{
				insert(temp1, K);
				temp1 = temp1->next;
				count = 0;
			}
			temp1 = temp1->next;
		}
		return head;
	}
}
void insert(struct node *temp, int k)
{
	struct node *temp2;
	temp2 = (struct node *)malloc(sizeof(struct node));
	temp2 -> num = k;
	temp2 -> next = temp->next;
	temp->next = temp2;
}
