#include<stdio.h>
#include<stdlib.h>
struct binary_tree
{
    int data;
    struct binary_tree* left, *right;
};

struct binary_tree *insert(int num)
{
    struct binary_tree *node=(struct binary_tree *)malloc(sizeof(struct binary_tree));
    node->data=num;
    node->right=node->left = NULL;
    return node;
}
 
int check(struct binary_tree *node)
{
   if (node==NULL)
       return 0;
   if ((node->left==NULL)&&(node->right==NULL))
       return 1;
   return 0;
}

int sum(struct binary_tree *root)
{
    int res=0;
    if (root != NULL)
    {
       
       if (check(root->left))
            res+=root->left->data;
       else 
            res+=sum(root->left);
    
        res+=sum(root->right);
    }
 
    return res;
}
 
int main()
{
    struct binary_tree *root  = insert(30);
    root->left                = insert(19);
    root->right               = insert(49);
    root->right->left         = insert(23);
    root->right->right        = insert(52);
    root->right->right->left  = insert(50);
    root->left->left          = insert(55);
    root->left->right         = insert(12);
    root->left->right->right  = insert(12);
    printf("Sum of left leaves is %d\n",sum(root));
    return 0;
}
