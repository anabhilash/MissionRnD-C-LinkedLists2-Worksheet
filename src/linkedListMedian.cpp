/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) 
{
	if (head != NULL)
	{
		struct node *temp = head,*temp1 = head;
		int count = 1, b = 0;
		while (temp != NULL)
		{
			if (!(count & 1))
			{
				b = temp1->num;
				temp1 = temp1->next;
			}
			count++;
			temp = temp->next;
		}
		if ((count & 1))
		{
			b = (b + temp1->num) / 2;
			return b;
		}
		else
		{
			return temp1->num;
		}
	}
	else
	{
		return -1;
	}
}
