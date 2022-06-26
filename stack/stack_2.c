/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasuh <jasuh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:02:30 by jasuh             #+#    #+#             */
/*   Updated: 2022/06/26 18:09:48 by jasuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef struct {
	int	stack[MAX_STACK_SIZE];
	int	top;
} STACK_TYPE;

void	init_stack(STACK_TYPE *arr)
{
	arr->top = -1;
	return;
}

int	is_full(STACK_TYPE *arr)
{
	return (arr->top == MAX_STACK_SIZE -1);
}

int	is_empty(STACK_TYPE *arr)
{
	return (arr->top == -1);
}

void	push(STACK_TYPE *arr, int item)
{
	if (is_full(arr))
	{
		fprintf(stderr, "stack 꽉 찼음\n");
		exit(1);
	}
	else 
	{
		arr->stack[++(arr->top)] = item;
		return ;
	}
}

int	pop(STACK_TYPE *arr)
{
	if (is_empty(arr))
	{
		fprintf(stderr, "stack 비었음\n");
		exit(1);
	}
	else
	{
		return arr->stack[arr->top--];
	}
}

int	peek(STACK_TYPE *arr)
{
	if (is_empty(arr))
	{
		fprintf(stderr, "stack 비었음\n");
		exit(1);
	}
	else
		return arr->stack[arr->top];
}

int	main(void)
{
	STACK_TYPE arr;
	init_stack(&arr);

	push(&arr, 1);
	push(&arr, 2);
	push(&arr, 3);
	
	printf("%d\n", pop(&arr));
	printf("%d\n", pop(&arr));
	printf("%d\n", pop(&arr));
	printf("%d\n", pop(&arr));
	return (0);
}
