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
int check(struct tree *node)
{
    if((node->left==NULL)&&(node->right!=NULL))
    {
        if(node->data==node->right->data)
            return 1;
        else
            return 0;
    }
    else if((node->right==NULL)&&(node->left!=NULL))
        
    {
        if(node->data==node->left->data)
            return 1;
        else
            return 0;
    }

    else
    {
        if((node->data==(node->left->data+node->right->data))||((node->data)==(2*(node->left->data+node->right->data))))
            return 1;
        else
            return 0;
    }
}
int sumtree(struct tree *node)
{
    int res,t1,t2;
    if(node==NULL)
        return 1;
    else if((node->left==NULL)&&(node->right==NULL))
        return 1;
    else
    {
        if(check(node))
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
    struct tree *root=insert(26);
    root->left=insert(10);
    root->right=insert(3);
    root->left->left=insert(4);
    root->left->right=insert(6);
    root->right->right=insert(3);
    flag=sumtree(root);
    if(flag==1)
        printf("It is sum tree\n");
    else
        printf("It is not sum tree\n");
    return 0;
}
