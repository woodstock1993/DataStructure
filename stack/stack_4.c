/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjh <sjh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:37:15 by jasuh             #+#    #+#             */
/*   Updated: 2022/06/27 15:38:57 by sjh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;

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

int check_matching(const char *pt) // 값을 변경하려면 에러 발생
{
    stack_type s;
    char ch, open_ch;
    int i, n = strlen(pt);
    init_stack(&s);

    for(int i = 0; i < n; i++)
    {
        ch = pt[i];
        switch(ch) 
        {
            case '[' : case '{' : case '(' :
                push(&s, ch);
                break;
            case ']' : case '}' : case ')':
                if (is_empty(&s)) return 0;
                else
                {
                    open_ch = pop(&s);
                    if ((open_ch == '(' && ch != ')') ||
                        (open_ch == '[' && ch != ']') ||
                        (open_ch == '{' && ch != '}')) {
                        return 0;
                    }
                }
                break;
        }
    }
    if (s.top == -1)
        return 1;
    else
        return 0;
}

int main(void)
{   
    char arr[] = "{([])}{(([[]]))}()";
    if (check_matching(arr) == 1)
        printf("%s, 괄호검사 성공\n", arr);
    else
        printf("%s, 괄호검사 실패\n", arr);
	return (0);
}