/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjh <sjh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 20:52:56 by sjh               #+#    #+#             */
/*   Updated: 2022/12/31 21:00:20 by sjh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 반복적 순회

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

#define SIZE 100
int top = -1;
TreeNode *stack[SIZE];

void push(TreeNode *p)
{
    if (top < SIZE -1)
    stack[++top] = p;
}

TreeNode *pop()
{
    TreeNode *p = NULL;
    if(top >= 0){
        p = stack[top--];
    }
    return p;
}

void inorder_iter(TreeNode *root)
{
    while (1) {
        for(; root; root = root->left) {
            push(root);
        }
        root = pop();
        
        if(!root) break;
        printf("[%d] ", root->data);
        root = root->right;
    }
}

TreeNode n7 = {7, 0, 0};
TreeNode n6 = {6, 0, 0};
TreeNode n5 = {5, 0, 0};
TreeNode n4 = {4, 0, 0};
TreeNode n3 = {3, &n6, &n7};
TreeNode n2 = {2, &n4, &n5};
TreeNode n1 = {1, &n2, &n3};

int main(void)
{
    printf("중위 순회=");
    inorder_iter(&n1);
    printf("\n");
    return 0;
}