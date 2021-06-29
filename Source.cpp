//Reverse Linked List using Stack(Linked List implementation)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct StackNode
{
	int data;
	struct StackNode *link;
}*top = NULL;				//struct StackNode *top = NULL

void pushStack(int num)
{
	struct StackNode *temp = (struct StackNode*)malloc(sizeof(struct StackNode));
	temp->data = num;
	temp->link = top;
	top = temp;
}
void popStack()
{
	if (top == NULL)
	{
		printf("Stack underflow \n");
		return;
	}
	struct StackNode *temp = top;
	int num = top->data;
	top = top->link;
	free(temp);
	//	printf("Deleted : %d \n", num);
}

struct LinkedListNode
{
	int data;
	struct LinkedListNode *link;
};

void display(struct LinkedListNode *head_ref)
{
	struct LinkedListNode *temp = head_ref;
	while (temp != NULL)
	{
		printf("%d  ", temp->data);
		temp = temp->link;
	}
}

LinkedListNode* pushLL(LinkedListNode *head_ref, int num)
{
	struct LinkedListNode *new_node = (struct LinkedListNode*)malloc(sizeof(struct LinkedListNode));
	new_node->data = num;
	new_node->link = head_ref;
	head_ref = new_node;
	return head_ref;
}

void appendLL(LinkedListNode *head_ref, int num)
{
	if (head_ref == NULL)
	{
		printf("This function cannot be used to add a node to an Empty list \n");
		return;
	}
	struct LinkedListNode *head_ref2 = head_ref;
	struct LinkedListNode *new_node = (struct LinkedListNode*) malloc(sizeof(struct LinkedListNode));
	new_node->data = num;
	new_node->link = NULL;
	while (head_ref2->link != NULL)
		head_ref2 = head_ref2->link;
	head_ref2->link = new_node;
}

LinkedListNode* reverseUsingStack(LinkedListNode *head_ref)
{
	struct LinkedListNode *ptr = head_ref, *ptr2 = NULL;
	int temp;
	while (ptr != NULL)
	{
		pushStack(ptr->data);
		ptr = ptr->link;
	}
	while (top != NULL)
	{
		temp = top->data;
		popStack();
		if (ptr2 == NULL)
			ptr2 = pushLL(ptr2, temp);
		else
			appendLL(ptr2, temp);
	}

	head_ref = ptr2;
	return head_ref;
}

void main()
{
	struct LinkedListNode *head = NULL;
	int choice, num;
	while (1)
	{
		printf("\n\n1. Display \n");
		printf("2. Add node to empty list / Add at beginning \n");
		printf("3. Add node at the end \n");
		printf("4. Reverse Linked List \n");
		printf("5. Exit \n");

		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			display(head);
			break;
		case 2:
			printf("Enter the number to be inserted: ");
			scanf("%d", &num);
			head = pushLL(head, num);
			break;
		case 3:
			printf("Enter the number to be inserted: ");
			scanf("%d", &num);
			appendLL(head, num);
			break;
		case 4:
			head = reverseUsingStack(head);
			break;
		case 5:
			exit(1);
		default: printf("Invalid choice \n\n");
		}
	}
	_getch();
}