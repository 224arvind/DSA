#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
}*top = NULL;

void push(int x)
{
	struct Node *t;
	t = (struct Node *)malloc(sizeof(struct Node));
	if(t == NULL)
	{
		printf("Stack is full\n");
	}

	else
	{
		t->data = x;
		t->next = top;
		top = t;
	}
}

int pop()
{
	struct Node *t;
	int x = -1;
	if(top == NULL)
	{
		printf("Stack is empty\n");
	}
	else
	{
		t = top;
		top = top->next;
		x = t->data;
		free(t);
	}
	return x;

}

void display()
{
	if(top == NULL)
	{
		printf("Stack is empty");
	}

	else
	{
		struct Node *t;
		t = top;
		while(t != NULL)
		{
			printf("%d ", t->data);
			t = t->next;
		}
		printf("\n");
	}
}

int peek()
{
	int x = -1;
	if(top == NULL)
	{
		printf("Stack is empty\n");
	}
	else
	{
		x = top->data;
	}
	return x;
}

int isEmpty()
{
	if(top == NULL)
	{
		return 1;
	}

	return 0;
}

int isFull()
{
	if(top == NULL)
	{
		return 0;
	}

	return 1;
}

int main()
{
	push(10);
	push(20);
	push(30);

	display();

	printf("%d \n", pop());
	display();
	printf("%d \n", peek());


	return 0;
}