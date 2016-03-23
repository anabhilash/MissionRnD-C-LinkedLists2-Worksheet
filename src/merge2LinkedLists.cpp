/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};
struct node * find(struct node * slave,struct node * master);

struct node * merge2LinkedLists(struct node *head1, struct node *head2)
{
	if (head1 == NULL)
	{
		return head2;
	}
	else if (head2 == NULL)
	{
		return head1;
	}
	else
	{
		struct node *master, *slave,*temp1,*temp2,*temp,*temp3;
		if ((head1->num) < (head2->num))
		{
			master = head1;
			slave = head2;
		}
		else
		{
			master = head2;
			slave = head1;
		}
		temp3 = master;
		while (slave != NULL)
		{
			while (master != NULL)
			{
				if (master->num > slave->num)
				{
					break;
				}
				temp = master;
				master = master->next;
			}
			if (master == NULL)
			{
				temp->next= slave;
				break;
			}
			else
			{
				temp1 = slave->next;
				temp2 = temp->next;
				temp->next = slave;
				slave->next = temp2;
				master = slave;
				slave = temp1;
			}

		}
		return temp3;
	}

}

