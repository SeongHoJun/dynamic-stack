#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

typedef int element;
typedef struct {
	element* data;
	int capacity;
	int top;
}StackType;	//data는 포인터로

void init_stack(StackType* sp)
{
	sp->top = -1;
	sp->capacity = 1;
	sp->data = (element*)malloc(sp->capacity * sizeof(element));
}

int is_empty(StackType* sp)
{
	return (sp->top == -1);
}
int is_full(StackType* sp)
{
	return (sp->top == (MAX_SIZE - 1));
}

void push(StackType* sp, element item)
{
	if (is_full(sp))
	{
		sp->capacity=sp->capacity*2;
		sp->data = (element*)realloc(sp->data, sp->capacity * sizeof(element));
	}
	sp->data[++(sp->top)] = item;
}

element pop(StackType* sp)
{
	if (is_empty(sp))
	{
		fprintf(stderr, "스택 공백 에러\n");
		return 1;
	}
	else
	{
		return sp->data[(sp->top)--];
	}
}

element peek(StackType* sp)
{
	if (is_empty(sp))
	{
		fprintf(stderr, "스택 공백 에러\n");
		return 1;
	}
	else return sp->data[sp->top];
}

int main()
{
	StackType sp;
	init_stack(&sp);

	srand(time(NULL));
	for (int i = 0; i < 30; i++)
	{
		int rand_num = rand() % 100 + 1;
		if (rand_num % 2 == 0)
		{

			push(&sp, rand_num);
			printf("%d\n", rand_num);
		}
		else
		{
			printf("%d\n", peek(&sp));
			pop(&sp);
		}
	}
}