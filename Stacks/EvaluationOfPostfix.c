// Video - 252

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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



int isOperand(char c)
{
	if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')')
	{
		return 0;
	}

	else
	{
		return 1;
	}
}

int evaluationOfPostfix(char *postfix)
{	
	int i = 0;
	while(postfix[i] != '\0')
	{
		if(isOperand(postfix[i]))
		{
			push(postfix[i++]-48);
		}
		else
		{
			int x2 = pop();
			int x1 = pop();
			int r = 0;
			switch(postfix[i])
			{
				case '+':r=x1+x2; break;
				case '-':r=x1-x2; break;
				case '*':r=x1*x2; break;
				case '/':r=x1/x2; break;
			}
			push(r);
			i++;
		}
	}
	return pop();

}

int main()
{

	char post[] = "234*+82/-";
	printf("\n%d",evaluationOfPostfix(post));


	return 0;
}