/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjh <sjh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:37:15 by jasuh             #+#    #+#             */
/*   Updated: 2022/06/26 20:52:29 by sjh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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
    return (arr->capacity-1 == (arr->top));
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
        return arr->data[(arr->top)--];    
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

int main(void)
{
    stack_type arr;
    init_stack(&arr);
    push(&arr, 1);
    push(&arr, 2);
    push(&arr, 3);	

    printf("%d\n", pop(&arr)); //3	
    printf("%d\n", pop(&arr)); //2
    printf("%d\n", pop(&arr)); //1
    printf("%d\n", pop(&arr)); // 비어있음
	free(arr.data);
    return (0);
}