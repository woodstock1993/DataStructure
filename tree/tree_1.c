/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjh <sjh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 19:15:41 by sjh               #+#    #+#             */
/*   Updated: 2022/12/31 20:06:53 by sjh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

// TreeNode 구조체 선언
typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode n7 = {7, 0, 0};
TreeNode n6 = {6, 0, 0};
TreeNode n5 = {5, 0, 0};
TreeNode n4 = {4, 0, 0};
TreeNode n3 = {3, &n6, &n7};
TreeNode n2 = {2, &n4, &n5};
TreeNode n1 = {1, &n2, &n3};

// 전위 순회
void preorder(TreeNode *root)
{
    if(root != 0)
    {
        printf("[%d] ", (*root).data);
        preorder(root->left);
        preorder(root->right);
    }
}

// 중위 순회
void inorder(TreeNode *root)
{
    if(root !=0)
    {
        inorder(root->left);
        printf("[%d] ", root->data);
        inorder(root->right);
    }
}

// 후위 순회
void postorder(TreeNode *root)
{   
    if(root!=0)
    {
        postorder(root->left);
        postorder(root->right);
        printf("[%d] ", root->data);
    }
}

int main(void) {
    preorder(&n1);
    printf("\n");
    
    inorder(&n1);
    printf("\n");
    
    postorder(&n1);
    return (0);
}