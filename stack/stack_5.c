#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;

typedef struct
{
	element *data;
	int top;
	int capacity;
} stack_type;

void init_stack(stack_type *arr)
{
	arr->top = -1;
	arr->capacity = 1;
	arr->data = (element *)malloc(sizeof(element) * (arr->capacity));
	if (!(arr->data))
		return;
}

void delete (stack_type *arr)
{
	free(arr);
}

int is_full(stack_type *arr)
{
	return (arr->capacity - 1 == (arr->top));
}

int is_empty(stack_type *arr)
{
	return (arr->top == -1);
}

void push(stack_type *arr, element item)
{
	if (is_full(arr))
	{
		arr->capacity *= 2;
		arr->data = realloc(arr->data, sizeof(element) * (arr->capacity));
		if (!(arr))
			return;
		arr->data[++(arr->top)] = item;
	}
	else
	{
		arr->data[++(arr->top)] = item;
	}
}

element pop(stack_type *arr)
{
	if (is_empty(arr))
	{
		fprintf(stderr, "stack이 비었습니다.\n");
		exit(1);
	}
	else
	{   
        char temp = (char)arr->data[(arr->top)];
        arr->data[(arr->top)] = 0;
        (arr->top)--;
		return temp;
	}
}

element peek(stack_type *arr)
{
	if (is_empty(arr))
	{
		fprintf(stderr, "stack 비었음\n");
		exit(1);
	}
	else
	{
		return arr->data[arr->top];
	}
}

int *postfix(char string[])
{   
    stack_type s;

    for(int i = 0; i < strlen(string); i ++)
    {
        char ch = string[i];
        if ('0' <= string[i] && string[i] <= '9')
        {
            int num = atoi(&ch);
            push(&s, num);
        }
    }
    return s.data;
}

int main(void)
{
    char arr[] = "12345";
    int *string;
    string = postfix(arr);
    return (0);
}