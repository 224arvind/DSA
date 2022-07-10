// Video - 241

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	char data;
	struct Node* next;
}*top = NULL;

void push(char x)
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
	char x = '0';
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
	char x = '0';
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

int isBalanced(char *exp)
{
	int i = 0;
	while(exp[i] != '\0')
	{
		if(exp[i] == '(')
		{
			push('(');
		}

		else if(exp[i] == ')')
		{
			if(top == NULL){
				return 0;
			}
			pop();
		}
		i++;
	}
	return isEmpty();
}

int main()
{

	char exp[] = "((a+b)*(c-d)";
	

	printf("%d\n", isBalanced(exp));
	return 0;
}