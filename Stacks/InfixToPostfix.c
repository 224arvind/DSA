// Video - 248

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
		x='0';
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

// operator with highest number have highest precedence
int precedence(char c)
{
	if(c == '+' || c == '-')
	{
		return 1;
	}

	else if(c == '*' || c == '/')
	{
		return 2;
	}

	return 0;
}
int isOperand(char c)
{
	if(c == '+' || c == '-' || c == '*' || c == '/')
	{
		return 0;
	}

	else
	{
		return 1;
	}
}

char * infixToPostfix(char *infix)
{
	char *postfix= (char *)malloc((strlen(infix)+2)*sizeof(char));
	int i = 0;
	int j = 0;
	while(infix[i] != '\0')
	{
		if(isOperand(infix[i]))
		{
			postfix[j++] = infix[i++];
		}

		else
		{
			if(precedence(infix[i]) > precedence(peek()))
			{
				push(infix[i++]);

			}
			else
			{
				postfix[j++] = pop();
			}
		}
	}

	while(!isEmpty())
	{
		postfix[j++] = pop();
	}

	postfix[j] = '\0';


	return postfix;
}


int main()
{

	char infix[] = "a+b*c-d/e";
	printf("%s",infixToPostfix(infix));


	return 0;
}