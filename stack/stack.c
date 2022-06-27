/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasuh <jasuh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 21:16:07 by jasuh             #+#    #+#             */
/*   Updated: 2022/06/26 21:16:19 by jasuh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef struct {
	int		student_no;
	char 	name[MAX_STRING];
	char 	address[MAX_STRING];
} element;

int top = -1;

element stack[MAX_STACK_SIZE];

int	is_full()
{
	return (top == MAX_STACK_SIZE -1);
}

int	is_empty()
{
	return (top == -1);
}

void	push(element item)
{
	if (is_full())
		fprintf(stderr, "스택포화\n");
	else
		stack[++top] = item;
}

element	pop()
{
	if (is_empty())
	{
		fprintf(stderr, "스택 비어있음\n");
		exit(1);
	}
	else
		return stack[top--];
}

element	peek()
{
	if (is_empty())
	{
		fprintf(stderr, "스택 비어있음\n");
		exit(1);
	}
	else
		return stack[top];
}

int	main(void) 
{
	element	p1 = {
		2013610022,
		"서재환",
		"도봉구 도봉로 136길 28"
	};

	element p2;

	printf("%d\n",is_empty());
	push(p1);
	p2 = pop();

	printf("%d\n", p2.student_no);
	printf("%s\n", p2.name);
	printf("%s\n", p2.address);
	return 0;
}
