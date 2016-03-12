#include <stdio.h>
#include <stdlib.h>
struct tree
{
    int data;
    struct tree *left, *right;
};
struct tree* insert(int num)
{
    struct tree *node=(struct tree *)malloc(sizeof(struct tree));
    node->data=num;
    node->left=node->right=NULL;
    return node;
}
int find(struct tree *node)
{
    int sum=0;
    if((node->left!=NULL)&&(node->right!=NULL))
        sum+=node->left->data+node->right->data+find(node->left)+find(node->right);
    else if((node->left==NULL)&&(node->right!=NULL))
        sum+=node->right->data+find(node->right);
    else if((node->left!=NULL)&&(node->right==NULL))
        sum+=node->left->data+find(node->left);
    return sum;
}
int sumtree(struct tree *node)
{
    int res,t1,t2,temp;
    if(node==NULL)
        return 1;
    else if((node->left==NULL)&&(node->right==NULL))
        return 1;
    else
    {
        temp=find(node);
        if(temp==node->data)
            res=1;
        else
            res=0;
    }
    if(res==1)
    {
        t1=sumtree(node->left);
        t2=sumtree(node->right);
        if((t1==1)&&(t2==1))
            return 1;
        else
            return 0;
    }
    else
        return 0;
}
int main()
{
    int flag;
    struct tree *root=insert(50);
    root->left=insert(18);
    root->right=insert(14);
    root->left->left=insert(5);
    root->left->left->left=insert(2);
    root->left->left->right=insert(3);
    root->left->right=insert(8);
    flag=sumtree(root);
    if(flag==1)
        printf("It is sum tree\n");
    else
        printf("It is not sum tree\n");
    return 0;
}
